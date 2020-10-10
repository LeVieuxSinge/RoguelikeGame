// Fill out your copyright notice in the Description page of Project Settings.

#include "Map/ProceduralMap.h"

//void FProceduralMap::ComputeBoundsCategory(TArray<FTile*>& InPathBoundsArray)
//{
//    /** Compute edge tile category (buildings, bounds) and add bounds to buildings without bounds. */
//    for (FTile* Tile : InPathBoundsArray)
//    {
//        /** Get adjacent playable tiles. */
//        TArray<FTile*> PlayableAdjacents = Tile->GetPlayAdjacentConnections();
//
//        /** Tile on edge of map OR Tile surrounded by play tiles OR Tile adjacent with no play tiles = bounds. */
//        if (Tile->GetConnectionsArray().Num() <= 5 || PlayableAdjacents.Num() == 4 || PlayableAdjacents.Num() == 0)
//        {
//            /** Set category. */
//            Tile->Category = "Bound";
//        }
//
//        /** Tile with one non-playable tile. */
//        else if (PlayableAdjacents.Num() == 3)
//        {
//            /** Look if adjacent non-playable tile as only one adjacent non-playable tile. */
//            FTile* AdjacentNonPlayable = Tile->GetNonPlayAdjacentConnections()[0];
//
//            if (AdjacentNonPlayable->GetNonPlayAdjacentConnections().Num() == 1) {
//                /** Set category. */
//                Tile->Category = "Bound";
//            }
//            else {
//                /** Set category. */
//                Tile->Category = "Building";
//            }
//        }
//
//        /** Set random. */
//        else
//        {
//            /** Set category. */
//            (float)(rand() / RAND_MAX) < BuildingBoundaryProbability ? Tile->Category = "Bound" : Tile->Category = "Building";
//        }
//
//        // Make sure buildings have bounds.
//        if (Tile->GetCategory() == "Building")
//        {
//            for (FTile* AdjacentTile : Tile->GetAdjacentConnections())
//            {
//                if (!AdjacentTile->IsUsed())
//                {
//                    /** Set it as used. */
//                    AdjacentTile->bUsed = true;
//                    /** Set category. */
//                    AdjacentTile->Category = "Bound";
//                    /** Add to outer array. */
//                    InPathBoundsArray.Add(AdjacentTile);
//                }
//            }
//        }
//    }
//}

//void FProceduralMap::SpawnPath(UWorld* World)
//{
//    for (FTile* Tile : Path)
//    {
//        /** Random tile actor. */
//        TSubclassOf<AActor> RandomActor = PathActors[rand() % PathActors.Num()];
//        FActorSpawnParameters SpawnParams;
//        World->SpawnActor<AActor>(RandomActor, Tile->GetPosition(), Tile->GetRotation(), SpawnParams);
//    }
//
//}

//void FProceduralMap::SpawnPathBounds(UWorld* World)
//{
//    for (FTile* Tile : PathBounds)
//    {
//        /** Random tile actor. */
//        TSubclassOf<AActor> RandomActor = BoundActors[rand() % BoundActors.Num()];
//        FActorSpawnParameters SpawnParams;
//        World->SpawnActor<AActor>(RandomActor, Tile->GetPosition(), Tile->GetRotation(), SpawnParams);
//    }
//}

void AProceduralMap::ConstructTilesheet()
{
    /** Assign index to tile for faster sorting */
    int32 NextIndex = 0;

    /** Get tile sheet center point */
    /** Performs a different operation if input is even*/
    int32 SheetCenterX;
    int32 SheetCenterY;
    Rows % 2 == 0 ? SheetCenterY = (TileSize * (Rows / 2)) - TileSize / 2 : SheetCenterY = TileSize * (Rows / 2);
    Columns % 2 == 0 ? SheetCenterX = (TileSize * (Columns / 2)) - TileSize / 2 : SheetCenterX = TileSize * (Columns / 2);

    /** Create tile sheet */
    /** For each Y (rows) and X (columns) */
    for (size_t y = 0; y < Rows; y++)
    {
        for (size_t x = 0; x < Columns; x++)
        {
            /** Create new position for tile */
            FVector TilePosition(TileSize * x, TileSize * y, 0);

            /** Displace every tile using center point so that the tile sheet is centered on its origin (0,0) */
            TilePosition.X -= SheetCenterX;
            TilePosition.Y -= SheetCenterY;

            /** Check if can be playable */
            /** If position on edge (first and last rows || first and last columns) */
            bool bCanBePlayable = false;
            if (y == 0 || y == (Rows - 1) || x == 0 || x == (Columns - 1)) {
                bCanBePlayable = false;
            }
            else {
                bCanBePlayable = true;
            }

            /** Create new tile. */
            FTile Tile;
            Tile.Index = NextIndex;
            Tile.Position = TilePosition;
            Tile.Size = TileSize;
            Tile.bCanBePlayable = bCanBePlayable;

            /** Add tile to output */
            TileSheet.Add(Tile);

            /** Update next index */
            NextIndex++;

        }
    }
}

void AProceduralMap::GenerateMap()
{
    UE_LOG(LogTemp, Warning, TEXT("Generating Map ..."));

    /** Create index array from tilesheet for reference. */
    TArray<int32> Tiles;
    for (FTile Tile : TileSheet)
    {
        Tiles.Add(Tile.Index);
    }

    /** Create an array of can be playable tiles. */
    TArray<int32> CanBePlayables = GetCanBePlayables(Tiles);

    /** Select random start tile, set it as used, playable, start category and add to path array */
    int32 StartTile = GetRandomTileFromArray(CanBePlayables);
	TileSheet[StartTile].bUsed = true;
    TileSheet[StartTile].bPlayable = true;
    TileSheet[StartTile].Category = "Start";

    /** Select random end tile in radius, set it as used, playable and end type. */
	int32 EndTile = GetRandomTileInRadius(CanBePlayables, StartTile, MinimumEndRadius);
    TileSheet[EndTile].bUsed = true;
    TileSheet[EndTile].bPlayable = true;
    TileSheet[EndTile].Category = "End";

    /** Generate a path from starting point to end point. */
    TArray<int32> Path = ComputePath(StartTile, EndTile, PathMinimumLength);

    /** Populate path bounds array. */
    TArray<int32> PathBounds = ComputePathBounds(Path);

    /** Spawn path actors. */
    SpawnPath(Path);

}

TArray<int32> AProceduralMap::ComputePath(int32 InStartTile, int32 InEndTile, float InPathMinimumLength)
{
    TArray<int32> OutPath;
    OutPath.Add(InStartTile);
    int32 CurrentTile = InStartTile;
    bool bEndTileFound = false;
    do {
        /** Get only adjacent playable tiles. */
        TArray<int32> CurrentPlayables = GetCanBePlayables(GetAdjacents(CurrentTile));
    
        /** Select random tile from playables. */
        int32 NextTile = GetRandomTileFromArray(CurrentPlayables);
    
        /** Tile is not already path. */
        if (!OutPath.Contains(NextTile))
        {
            /** Is end tile found. */
            if (NextTile == InEndTile)
            {
                bEndTileFound = true;
            }
            else
            {
                TileSheet[NextTile].bUsed = true;
                TileSheet[NextTile].bPlayable = true;
                TileSheet[NextTile].Category = "Path";
            }
            /** Add to path array. */
            OutPath.Add(NextTile);
            /** Set next tile as current. */
            CurrentTile = NextTile;
        }
        else {
            /** Change the random tile selection depending of whether or not the end tile as been found. */
            if (!bEndTileFound) {
                /** Select closest tile from end. */
                CurrentTile = GetClosestTileFrom(OutPath, InEndTile);
            }
            else {
                /** Select random tile from path. */
                CurrentTile = GetRandomTileFromArray(OutPath);
            }
        }
    
    } while (!bEndTileFound || OutPath.Num() < InPathMinimumLength);
    return OutPath;
}

TArray<int32> AProceduralMap::ComputePathBounds(TArray<int32> InPath)
{
    TArray<int32> OutPathBounds;
    for (int32 Tile : InPath)
    {
        /** For each path tile, search in surrounding tiles. */
        for (int32 Bound : GetSurroundings(Tile))
        {
            /** If not playable and index is not already in array. */
            if (!TileSheet[Bound].bPlayable && !OutPathBounds.Contains(Bound))
            {
                /** Set it as used. */
                TileSheet[Bound].bUsed = true;
                /** Add to outer array. */
                OutPathBounds.Add(Bound);
            }
        }
    }
    return OutPathBounds;
}

void AProceduralMap::SpawnPath(TArray<int32> InPath)
{
    for (int32 Tile : InPath)
    {
        /** Start tile. */
        if (TileSheet[Tile].Category == "Start")
        {
            if (StartActors.Num() != 0)
            {
                TSubclassOf<AActor> RandomActor = StartActors[rand() % StartActors.Num()];
                FActorSpawnParameters SpawnParams;
                GetWorld()->SpawnActor<AActor>(RandomActor, TileSheet[Tile].Position, TileSheet[Tile].Rotation, SpawnParams);
            }
        }
        /** End tile. */
        if (TileSheet[Tile].Category == "End")
        {
            if (EndActors.Num() != 0)
            {
                TSubclassOf<AActor> RandomActor = EndActors[rand() % EndActors.Num()];
                FActorSpawnParameters SpawnParams;
                GetWorld()->SpawnActor<AActor>(RandomActor, TileSheet[Tile].Position, TileSheet[Tile].Rotation, SpawnParams);
            }
        }
        /** Path tile. */
        if (TileSheet[Tile].Category == "Path")
        {
            if (PathActors.Num() != 0)
            {
                TSubclassOf<AActor> RandomActor = PathActors[rand() % PathActors.Num()];
                FActorSpawnParameters SpawnParams;
                GetWorld()->SpawnActor<AActor>(RandomActor, TileSheet[Tile].Position, TileSheet[Tile].Rotation, SpawnParams);
            }
        }
    }
}

int32 AProceduralMap::GetRandomTileFromArray(TArray<int32> InTiles)
{
    return InTiles[rand() % InTiles.Num()];
}

int32 AProceduralMap::GetRandomTileInRadius(TArray<int32> InTiles, int32 InSourceTile, float InMinimumRadius)
{
    int32 OutIndex;
    float Distance;
    do
    {
        OutIndex = GetRandomTileFromArray(InTiles);
        Distance = FVector::Dist(TileSheet[InSourceTile].Position, TileSheet[OutIndex].Position);
    } while (Distance < InMinimumRadius);
    return OutIndex;
}

int32 AProceduralMap::GetClosestTileFrom(TArray<int32> InTiles, int32 InTargetTile)
{
    int32 OutTile = GetRandomTileFromArray(InTiles);
    for (int32 Tile : InTiles)
    {
        FVector::Dist(TileSheet[Tile].Position, TileSheet[InTargetTile].Position) < FVector::Dist(TileSheet[OutTile].Position, TileSheet[InTargetTile].Position) ? OutTile = Tile : NULL;
    }
    return OutTile;
}

TArray<int32> AProceduralMap::GetAdjacents(int32 InTile)
{
    TArray<int32> OutArray;
    for (FTile Tile : TileSheet)
    {
        if (Tile.Position.Equals(GetTopPosition(InTile)) || Tile.Position.Equals(GetRightPosition(InTile)) || Tile.Position.Equals(GetBottomPosition(InTile)) || Tile.Position.Equals(GetLeftPosition(InTile)))
        {
            OutArray.Add(Tile.Index);
        }
    }
    return OutArray;
}

TArray<int32> AProceduralMap::GetCorners(int32 InTile)
{
    TArray<int32> OutArray;
    for (FTile Tile : TileSheet)
    {
        if (Tile.Position.Equals(GetTopRightPosition(InTile)) || Tile.Position.Equals(GetBottomRightPosition(InTile)) || Tile.Position.Equals(GetBottomLeftPosition(InTile)) || Tile.Position.Equals(GetTopLeftPosition(InTile)))
        {
            OutArray.Add(Tile.Index);
        }
    }
    return OutArray;
}

TArray<int32> AProceduralMap::GetSurroundings(int32 InTile)
{
    TArray<int32> OutArray;
    OutArray += GetAdjacents(InTile);
    OutArray += GetCorners(InTile);
    return OutArray;
}

TArray<int32> AProceduralMap::GetCanBePlayables(TArray<int32> InTiles)
{
    TArray<int32> OutArray;
    for (int32 Tile : InTiles)
    {
        if (TileSheet[Tile].bCanBePlayable)
        {
            OutArray.Add(TileSheet[Tile].Index);
        }
    }
    return OutArray;
}

TArray<int32> AProceduralMap::GetPlayables(TArray<int32> InTiles)
{
    TArray<int32> OutArray;
    for (int32 Tile : InTiles)
    {
        if (TileSheet[Tile].bPlayable)
        {
            OutArray.Add(TileSheet[Tile].Index);
        }
    }
    return OutArray;
}

TArray<int32> AProceduralMap::GetNonPlayables(TArray<int32> InTiles)
{
    TArray<int32> OutArray;
    for (int32 Tile : InTiles)
    {
        if (!TileSheet[Tile].bPlayable)
        {
            OutArray.Add(TileSheet[Tile].Index);
        }
    }
    return OutArray;
}

FVector AProceduralMap::GetTopPosition(int32 InTile)
{
    return FVector(TileSheet[InTile].Position.X + TileSheet[InTile].Size, TileSheet[InTile].Position.Y, TileSheet[InTile].Position.Z);
}

FVector AProceduralMap::GetTopRightPosition(int32 InTile)
{
    return FVector(TileSheet[InTile].Position.X + TileSheet[InTile].Size, TileSheet[InTile].Position.Y + TileSheet[InTile].Size, TileSheet[InTile].Position.Z);
}

FVector AProceduralMap::GetRightPosition(int32 InTile)
{
    return FVector(TileSheet[InTile].Position.X, TileSheet[InTile].Position.Y + TileSheet[InTile].Size, TileSheet[InTile].Position.Z);
}

FVector AProceduralMap::GetBottomRightPosition(int32 InTile)
{
    return FVector(TileSheet[InTile].Position.X - TileSheet[InTile].Size, TileSheet[InTile].Position.Y - TileSheet[InTile].Size, TileSheet[InTile].Position.Z);
}

FVector AProceduralMap::GetBottomPosition(int32 InTile)
{
    return FVector(TileSheet[InTile].Position.X - TileSheet[InTile].Size, TileSheet[InTile].Position.Y, TileSheet[InTile].Position.Z);
}

FVector AProceduralMap::GetBottomLeftPosition(int32 InTile)
{
    return FVector(TileSheet[InTile].Position.X - TileSheet[InTile].Size, TileSheet[InTile].Position.Y - TileSheet[InTile].Size, TileSheet[InTile].Position.Z);
}

FVector AProceduralMap::GetLeftPosition(int32 InTile)
{
    return FVector(TileSheet[InTile].Position.X, TileSheet[InTile].Position.Y - TileSheet[InTile].Size, TileSheet[InTile].Position.Z);
}

FVector AProceduralMap::GetTopLeftPosition(int32 InTile)
{
    return FVector(TileSheet[InTile].Position.X + TileSheet[InTile].Size, TileSheet[InTile].Position.Y - TileSheet[InTile].Size, TileSheet[InTile].Position.Z);
}
