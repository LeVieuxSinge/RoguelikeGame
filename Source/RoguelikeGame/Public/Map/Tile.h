// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TileConnections.h"
#include "Tile.generated.h"

USTRUCT()
struct FTile
{
	GENERATED_BODY()

	/** Constructor */
	FTile() {}

	FTile(int32 InIndex, FVector InPosition, float InSize, bool InCanBePlayable)
		: Index(InIndex)
		, Position(InPosition)
		, Size(InSize)
		, bCanBePlayable(InCanBePlayable)
	{}

	/** Index */
	int32 Index;
	int32 GetIndex() { return Index; }

	/** Category */
	FString Category;
	FString GetCategory() { return Category; }

	/** Type */
	FString Type;
	FString GetType() { return Type; }

	/** Position */
	FVector Position;
	FVector GetPosition() { return Position; }

	/** Rotation */
	float Rotation;
	float GetRotation() { return Rotation; }

	/** Size */
	float Size;
	float GetSize() { return Size; }

	/** CanBePlayable */
	bool bCanBePlayable = false;
	bool CanBePlayable() { return bCanBePlayable; }

	/** Playable */
	bool bPlayable = false;
	bool IsPlayable() { return bPlayable; }

	/** Used */
	bool bUsed = false;
	bool IsUsed() { return bUsed; }

	/** Connections */
	FTileConnections Connections;
	FTileConnections GetConnections() { return Connections; }
	void ComputeConnections(TArray<FTile>& InTileArray)
	{
		Connections.Compute(InTileArray, Position, Size);
	}

	/** Reset */
	void Reset()
	{
		Category = nullptr;
		Type = nullptr;
		Rotation = 0;
		bPlayable = false;
		bUsed = false;
	}

};