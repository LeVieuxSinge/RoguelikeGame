// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tile.h"
#include "TileConnections.generated.h"

USTRUCT()
struct FTileConnections
{
	GENERATED_BODY()

	/** Constructor */
	FTileConnections() {}

	/** Connections */
	FTile Top;
	FTile TopRight;
	FTile Right;
	FTile BottomRight;
	FTile Bottom;
	FTile BottomLeft;
	FTile Left;
	FTile TopLeft;

	/** Array */
	TArray<FTile> AsArray;
	TArray<FTile> AsArray() { return AsArray; }

	/** Adjacents */
	TArray<FTile> Adjacents;
	TArray<FTile> GetAdjacents() { return Adjacents; }

	/** Corners */
	TArray<FTile> Corners;
	TArray<FTile> GetCorners() { return Corners; }

	/** Computes the connections */
	void Compute(TArray<FTile>& InTileArray, FVector InPosition, int32 InSize)
	{
		for (FTile Tile : InTileArray)
		{
			/** Top Tile */
			if (Tile.GetPosition() == FVector(InPosition.X + InSize, InPosition.Y, InPosition.Z))
			{
				Top = Tile;
				AsArray.Add(Top);
				Adjacents.Add(Top);
			}

			/** Top Right Tile */
			else if (Tile.GetPosition() == FVector(InPosition.X + InSize, InPosition.Y + InSize, InPosition.Z))
			{
				TopRight = Tile;
				AsArray.Add(TopRight);
				Corners.Add(TopRight);
			}

			/** Right Tile */
			else if (Tile.GetPosition() == FVector(InPosition.X, InPosition.Y + InSize, InPosition.Z))
			{
				Right = Tile;
				AsArray.Add(Right);
				Adjacents.Add(Right);
			}

			/** Bottom Right Tile */
			else if (Tile.GetPosition() == FVector(InPosition.X - InSize, InPosition.Y + InSize, InPosition.Z))
			{
				BottomRight = Tile;
				AsArray.Add(BottomRight);
				Corners.Add(BottomRight);
			}

			/** Bottom Tile */
			else if (Tile.GetPosition() == FVector(InPosition.X - InSize, InPosition.Y, InPosition.Z))
			{
				Bottom = Tile;
				AsArray.Add(Bottom);
				Adjacents.Add(Bottom);
			}

			/** Bottom Left Tile */
			else if (Tile.GetPosition() == FVector(InPosition.X - InSize, InPosition.Y - InSize, InPosition.Z))
			{
				BottomLeft = Tile;
				AsArray.Add(BottomLeft);
				Corners.Add(BottomLeft);
			}

			/** Left Tile */
			else if (Tile.GetPosition() == FVector(InPosition.X, InPosition.Y - InSize, InPosition.Z))
			{
				Left = Tile;
				AsArray.Add(Left);
				Adjacents.Add(Left);
			}

			/** Top Left Tile */
			else if (Tile.GetPosition() == FVector(InPosition.X + InSize, InPosition.Y - InSize, InPosition.Z))
			{
				TopLeft = Tile;
				AsArray.Add(TopLeft);
				Corners.Add(TopLeft);
			}

		}

	}

};
