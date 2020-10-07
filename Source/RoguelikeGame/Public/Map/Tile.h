// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
	FRotator Rotation;
	FRotator GetRotation() { return Rotation; }

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

	/** Reset */
	void Reset()
	{
		Category = nullptr;
		Type = nullptr;
		Rotation = FRotator();
		bPlayable = false;
		bUsed = false;
	}

	/** Connections */
	TMap<FString, FTile*> Connections;
	TArray<FTile*> GetConnectionsArray()
	{
		TArray<FTile*> OutputArray;
		for (auto& Tile : Connections)
		{
			Tile.Value != nullptr ? OutputArray.Add(Tile.Value) : NULL;
		}
		return OutputArray;
	}
	TArray<FTile*> GetAdjacentConnections()
	{
		TArray<FTile*> OutputArray;
		for (auto& Tile : Connections)
		{
			if (Tile.Key == "Top" || Tile.Key == "Right" || Tile.Key == "Bottom" || Tile.Key == "Left")
			{
				Tile.Value != nullptr ? OutputArray.Add(Tile.Value) : NULL;
			}
		}
		return OutputArray;
	}
	TArray<FTile*> GetPlayAdjacentConnections()
	{
		TArray<FTile*> OutputArray;
		for (auto& Tile : Connections)
		{
			if (Tile.Key == "Top" || Tile.Key == "Right" || Tile.Key == "Bottom" || Tile.Key == "Left")
			{
				if (Tile.Value->IsPlayable())
				{
					Tile.Value != nullptr ? OutputArray.Add(Tile.Value) : NULL;
				}
			}
		}
		return OutputArray;
	}
	TArray<FTile*> GetNonPlayAdjacentConnections()
	{
		TArray<FTile*> OutputArray;
		for (auto& Tile : Connections)
		{
			if (Tile.Key == "Top" || Tile.Key == "Right" || Tile.Key == "Bottom" || Tile.Key == "Left")
			{
				if (!Tile.Value->IsPlayable())
				{
					Tile.Value != nullptr ? OutputArray.Add(Tile.Value) : NULL;
				}
			}
		}
		return OutputArray;
	}
	TArray<FTile*> GetCornerConnections()
	{
		TArray<FTile*> OutputArray;
		for (auto& Tile : Connections)
		{
			if (Tile.Key == "TopRight" || Tile.Key == "BottomRight" || Tile.Key == "BottomLeft" || Tile.Key == "TopLeft")
			{
				Tile.Value != nullptr ? OutputArray.Add(Tile.Value) : NULL;
			}
		}
		return OutputArray;
	}
	void ComputeConnections(TArray<FTile>& InTileArray)
	{
		for (FTile Tile : InTileArray)
		{
			/** Top Tile */
			if (Tile.GetPosition() == FVector(Position.X + Size, Position.Y, Position.Z))
			{
				Connections.Add("Top", &Tile);
			}

			/** Top Right Tile */
			else if (Tile.GetPosition() == FVector(Position.X + Size, Position.Y + Size, Position.Z))
			{
				Connections.Add("TopRight", &Tile);
			}

			/** Right Tile */
			else if (Tile.GetPosition() == FVector(Position.X, Position.Y + Size, Position.Z))
			{
				Connections.Add("Right", &Tile);
			}

			/** Bottom Right Tile */
			else if (Tile.GetPosition() == FVector(Position.X - Size, Position.Y + Size, Position.Z))
			{
				Connections.Add("BottomRight", &Tile);
			}

			/** Bottom Tile */
			else if (Tile.GetPosition() == FVector(Position.X - Size, Position.Y, Position.Z))
			{
				Connections.Add("Bottom", &Tile);
			}

			/** Bottom Left Tile */
			else if (Tile.GetPosition() == FVector(Position.X - Size, Position.Y - Size, Position.Z))
			{
				Connections.Add("BottomLeft", &Tile);
			}

			/** Left Tile */
			else if (Tile.GetPosition() == FVector(Position.X, Position.Y - Size, Position.Z))
			{
				Connections.Add("Left", &Tile);
			}

			/** Top Left Tile */
			else if (Tile.GetPosition() == FVector(Position.X + Size, Position.Y - Size, Position.Z))
			{
				Connections.Add("TopLeft", &Tile);
			}

		}
	}

};