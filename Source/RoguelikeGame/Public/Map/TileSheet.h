// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tile.h"
#include "TileSheet.generated.h"

USTRUCT(Blueprintable)
struct FTileSheet
{
	GENERATED_BODY()

	/** Constructor */
	FTileSheet()
		: Rows(10)
		, Columns(10)
		, TileSize(1000)
	{
		CreateTileSheet();
	};

	/** Rows */
	UPROPERTY(EditDefaultsOnly)
	int32 Rows;

	/** Columns */
	UPROPERTY(EditDefaultsOnly)
	int32 Columns;

	/** TileSize */
	UPROPERTY(EditDefaultsOnly)
	int32 TileSize;

	/** Output */
	TArray<FTile> Output;
	TArray<FTile> GetOutput() { return Output; }

	/** Create the tile sheet */
	void CreateTileSheet() {

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

				/** Add tile to output */
				Output.Add(FTile(NextIndex, TilePosition, TileSize, bCanBePlayable));

				/** Update next index */
				NextIndex++;

			}
		}

		/** Compute tiles' connections */
		for (FTile Tile : Output)
		{
			Tile.ComputeConnections(Output);
		}

	}

};

