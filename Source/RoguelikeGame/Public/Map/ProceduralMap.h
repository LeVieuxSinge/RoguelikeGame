// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RoguelikeGame.h"
#include "TileSheet.h"
#include "ProceduralMap.generated.h"

UCLASS(Blueprintable)
class ROGUELIKEGAME_API UProceduralMap : public UObject
{
	GENERATED_BODY()

public:
	/** Constructor */
	UProceduralMap() {}

	/** Tile sheet */
	UPROPERTY(EditDefaultsOnly)
	FTileSheet TileSheet;

	/** Minimum distance between the starting point and the end. */
	UPROPERTY(EditDefaultsOnly)
	float MinimumEndDistance;

	/** Minimum amount of tile the path needs to have. */
	UPROPERTY(EditDefaultsOnly)
	int32 MinimumPathTile;

	/** Boundary probability for building tiles. */
	UPROPERTY(EditDefaultsOnly)
	float BuildingBoundaryProbability;

	/** Actors to spawn as path. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSubclassOf<AActor>> PathActors;

	/** Actors to spawn as building. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSubclassOf<AActor>> BuildingActors;

	UFUNCTION(BlueprintCallable, Category = "Map")
	void Generate();

};
