// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapGenerator.generated.h"

UCLASS()
class ROGUELIKEGAME_API AMapGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ------------- //
	// GENERATOR SETTINGS
	// ------------- //

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generator")
		int32 MapSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generator")
		int32 MapSizeY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generator")
		int32 TileSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Generator")
		TSubclassOf<AActor> StartingActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Generator")
		TSubclassOf<AActor> EndActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Generator")
		TArray<TSubclassOf<AActor>> InnerActors;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Generator")
		TSubclassOf<AActor> OuterActor;

	// ------------- //
	// TILE MAP DATA
	// ------------- //

	UPROPERTY(BlueprintReadOnly)
		TArray<FVector> T_InPos;
	UPROPERTY(BlueprintReadOnly)
		TArray<FVector> T_OutPos;
	UPROPERTY(BlueprintReadOnly)
		TArray<int32> T_Types;
	UPROPERTY(BlueprintReadOnly)
		TArray<FVector> T_PlayPos;
	UPROPERTY(BlueprintReadOnly)
		TArray<FVector> T_NonPlayPos;
	UPROPERTY(BlueprintReadOnly)
		FVector T_StartPos;
	UPROPERTY(BlueprintReadOnly)
		FVector T_EndPos;
	UPROPERTY(BlueprintReadOnly)
		int32 T_StartIndex;
	UPROPERTY(BlueprintReadOnly)
		int32 T_EndIndex;

	// ------------- //
	// GENERATOR FUNCTIONS
	// ------------- //

	UFUNCTION(BlueprintCallable)
		void CreateTileSheet();

	UFUNCTION(BlueprintCallable)
		void TileMapAlgorithm();

	// Map algorithm internal functions
	void GetSurroundingTiles(FVector TilePosition, TArray<int32>& IndexArray, TArray<int32>& TypeArray, TArray<FVector>& PositionArray);

	UFUNCTION(BlueprintCallable)
		void SpawnActor(TSubclassOf<AActor> Actor, FVector Loc, FRotator Rot);

	UFUNCTION(BlueprintCallable)
		void SpawnInnerTiles();

	UFUNCTION(BlueprintCallable)
		void SpawnOuterTiles();

};
