// Fill out your copyright notice in the Description page of Project Settings.

#include "Map/ProceduralMap.h"

void UProceduralMap::Generate()
{

	/** Clean arrays. */
	TArray<FTile*> Path;
	TArray<FTile*> PathBounds;

	/** Clean input. Because tiles are referenced, their base values are changed. Thus misleading the generator */
	for (FTile Tile : TileSheet.GetOutput())
	{
		Tile.Reset();
	}

	/** Create an array for the playable tiles. */
	TArray<FTile*> PlayableTiles;
	for (FTile Tile : TileSheet.GetOutput())
	{
		Tile.CanBePlayable() ? PlayableTiles.Add(&Tile) : NULL;
	}

	/** Select random start tile, set it as used, playable, start category and add to path array */
	FTile* StartingTile;
	StartingTile = PlayableTiles[floor((float)PlayableTiles.Num() * (float)(rand()/RAND_MAX))];
	StartingTile->bUsed = true;
	StartingTile->bPlayable = true;
	StartingTile->Category = "Start";
	Path.Add(StartingTile);

	/** Select random end tile in radius, set it as used, playable and end type. */
	FTile* EndingTile;
	float Distance;
	do {
		EndingTile = PlayableTiles[floor((float)PlayableTiles.Num() * (float)(rand() / RAND_MAX))];
		Distance = FVector::Dist(StartingTile->GetPosition(), EndingTile->GetPosition());
	} while (Distance < MinimumEndDistance);
	EndingTile->bUsed = true;
	EndingTile->bPlayable = true;
	EndingTile->Category = "End";

    /** Generate a path from starting point to end point. */
    FTile* CurrentTile = StartingTile;
    bool bEndTileFound = false;
    do {
        /** Get only adjacent playable tiles. */
        TArray<FTile*> CurrentPlayables;
        for (FTile* Tile : CurrentTile->GetAdjacentConnections())
        {
            Tile->CanBePlayable() ? CurrentPlayables.Add(Tile) : NULL;
        }

        /** Select random tile from playables. */
        FTile* NextTile = CurrentPlayables[floor(CurrentPlayables.Num() * (float)(rand() / RAND_MAX))];

        /** Is end tile found. */
        NextTile->GetIndex() == EndingTile->GetIndex() ? bEndTileFound = true : NULL;

        /** Tile is not already path. */
        if (!Path.Contains(NextTile))
        {
            /** If not end tile. */
            if (NextTile->GetCategory() != "End") {
                /** Set it as used, playable and street type. */
                NextTile->bUsed = true;
                NextTile->bPlayable = true;
                NextTile->Category = "Path";
            }
            /** Add to path array. */
            Path.Add(NextTile);
            /** Set next tile as current. */
            CurrentTile = NextTile;
        }
        else {
            /** Change the random tile selection depending of wheter or not the end tile as been found. */
            if (!bEndTileFound) {
                /** Select closest tile from end. */
                for (FTile* Tile : Path)
                {
                    FVector::Dist(Tile->GetPosition(), EndingTile->GetPosition()) < FVector::Dist(CurrentTile->GetPosition(),EndingTile->GetPosition()) ? CurrentTile = Tile : NULL;
                }
            }
            else {
                /** Select random tile from path. */
                CurrentTile = Path[floor(Path.Num() * (float)(rand() / RAND_MAX))];
            }
        }

    } while (!bEndTileFound || Path.Num() < MinimumPathTile);

    /** Populate path bounds array. */
    for (FTile* Tile : Path)
    {
        /** For each path tile, search in surrounding tiles. */
        for (FTile* Bound : Tile->GetConnectionsArray())
        {
            /** If not playable and index is not already in array. */
            if (Bound->IsPlayable() && !PathBounds.Contains(Bound))
            {
                /** Set it as used. */
                Bound->bUsed = true;
                /** Add to outer array. */
                PathBounds.Add(Bound);
            }
        }
    }

    /** Compute edge tile category (buildings, bounds) and add bounds to buildings without bounds. */
    for (FTile* Tile : PathBounds)
    {
        /** Get adjacent playable tiles. */
        TArray<FTile*> PlayableAdjacents = Tile->GetPlayAdjacentConnections();

        /** Tile on edge of map OR Tile surrounded by play tiles OR Tile adjacent with no play tiles = bounds. */
        if (Tile->GetConnectionsArray().Num() <= 5 || PlayableAdjacents.Num() == 4 || PlayableAdjacents.Num() == 0)
        {
            /** Set category. */
            Tile->Category = "Bound";
        }

        /** Tile with one non-playable tile. */
        else if (PlayableAdjacents.Num() == 3)
        {
            /** Look if adjacent non-playable tile as only one adjacent non-playable tile. */
            FTile* AdjacentNonPlayable = Tile->GetNonPlayAdjacentConnections()[0];

            if (AdjacentNonPlayable->GetNonPlayAdjacentConnections().Num() == 1) {
                /** Set category. */
                Tile->Category = "Bound";
            }
            else {
                /** Set category. */
                Tile->Category = "Building";
            }
        }

        /** Set random. */
        else
        {
            /** Set category. */
            (float)(rand() / RAND_MAX) < BuildingBoundaryProbability ? Tile->Category = "Bound" : Tile->Category = "Building";
        }

        // Make sure buildings have bounds.
        if (Tile->GetCategory()== "Building")
        {
            for (FTile* AdjacentTile : Tile->GetAdjacentConnections())
            {
                if (!AdjacentTile->IsUsed())
                {
                    /** Set it as used. */
                    AdjacentTile->bUsed = true;
                    /** Set category. */
                    AdjacentTile->Category = "Bound";
                    /** Add to outer array. */
                    PathBounds.Add(AdjacentTile);
                }
            }
        }
    }

    /** Spawn actors */
    for (FTile* Tile : Path)
    {
        /** Random tile actor. */
        TSubclassOf<AActor> RandomActor = PathActors[floor(PathActors.Num() * (float)(rand() / RAND_MAX))];

        FActorSpawnParameters SpawnParams;
        GetWorld()->SpawnActor<AActor>(RandomActor, Tile->GetPosition(), Tile->GetRotation(), SpawnParams);
    }

}
