// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RoguelikeGame.h"
#include "Tile.h"
#include "ProceduralMap.generated.h"

UCLASS(BlueprintType, Blueprintable)
class ROGUELIKEGAME_API AProceduralMap : public AActor
{
	GENERATED_BODY()

private:

	/** Tilesheet array. */
	TArray<FTile> TileSheet;

public:

	/** Constructor */
	AProceduralMap() {}

	/** Columns or width of tile sheet. */
	UPROPERTY(EditAnywhere, Category = TileSheet)
	int32 Columns;

	/** Rows or height of tile sheet. */
	UPROPERTY(EditAnywhere, Category = TileSheet)
	int32 Rows;

	/** Size of each tile. */
	UPROPERTY(EditAnywhere, Category = TileSheet)
	int32 TileSize;

	/** Minimum radius between the starting point and the end. */
	UPROPERTY(EditAnywhere, Category = Generator)
	float MinimumEndRadius;

	/** Minimum amount of tile the path needs to have. */
	UPROPERTY(EditAnywhere, Category = Generator)
	int32 PathMinimumLength;

	/** Actors to spawn as start. */
	UPROPERTY(EditAnywhere, Category = Render)
	TArray<TSubclassOf<AActor>> StartActors;

	/** Actors to spawn as end. */
	UPROPERTY(EditAnywhere, Category = Render)
	TArray<TSubclassOf<AActor>> EndActors;

	/** Actors to spawn as path. */
	UPROPERTY(EditAnywhere, Category = Render)
	TArray<TSubclassOf<AActor>> PathActors;

	/** Actors to spawn as building. */
	UPROPERTY(EditAnywhere, Category = Render)
	TArray<TSubclassOf<AActor>> BoundActors;

	/** Constructs the tile sheet. */
	UFUNCTION(BlueprintCallable, Category = ProceduralMap)
	void ConstructTilesheet();

	/** Generates a new map. */
	UFUNCTION(BlueprintCallable, Category = ProceduralMap)
	void GenerateMap();

	/** Generator internal functions. */
	TArray<int32> ComputePath(int32 InStartTile, int32 InEndTile, float InPathMinimumLength);
	TArray<int32> ComputePathBounds(TArray<int32> InPath);
	//void ComputeBoundsCategory(TArray<FTile*>& InPathBoundsArray);

	/** World interactions. */
	void SpawnPath(TArray<int32> InPath);
	//void SpawnPathBounds(UWorld* World);

	/** Tile queries. */
	int32 GetRandomTileFromArray(TArray<int32> InTiles);
	int32 GetRandomTileInRadius(TArray<int32> InTiles, int32 InSourceTile, float InMinimumRadius);
	int32 GetClosestTileFrom(TArray<int32> InTiles, int32 InTargetTile);

	/** Tile getters. */
	TArray<int32> GetAdjacents(int32 InTiles);
	TArray<int32> GetCorners(int32 InTile);
	TArray<int32> GetSurroundings(int32 InTile);
	TArray<int32> GetCanBePlayables(TArray<int32> InTiles);
	TArray<int32> GetPlayables(TArray<int32> InTiles);
	TArray<int32> GetNonPlayables(TArray<int32> InTiles);
	FVector GetTopPosition(int32 InTile);
	FVector GetTopRightPosition(int32 InTile);
	FVector GetRightPosition(int32 InTile);
	FVector GetBottomRightPosition(int32 InTile);
	FVector GetBottomPosition(int32 InTile);
	FVector GetBottomLeftPosition(int32 InTile);
	FVector GetLeftPosition(int32 InTile);
	FVector GetTopLeftPosition(int32 InTile);

};
