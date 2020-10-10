// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tile.generated.h"

USTRUCT()
struct FTile
{
	GENERATED_BODY()

	/** Constructor */
	FTile()
		: Index(0)
		, Category(TEXT("NULL"))
		, Type(TEXT("NULL"))
		, Position(0, 0, 0)
		, Rotation(0, 0, 0)
		, Size(0)
		, bCanBePlayable(false)
		, bPlayable(false)
		, bUsed(false)
	{}

	/** Variables*/
	int32 Index;
	FName Category;
	FName Type;
	FVector Position;
	FRotator Rotation;
	float Size;
	bool bCanBePlayable;
	bool bPlayable;
	bool bUsed;

};