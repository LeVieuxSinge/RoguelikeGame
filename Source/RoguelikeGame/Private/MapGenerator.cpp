// Fill out your copyright notice in the Description page of Project Settings.


#include "MapGenerator.h"

// Sets default values
AMapGenerator::AMapGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMapGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Constructs the tile sheet used for map generation
void AMapGenerator::CreateTileSheet()
{

	// Debugging
	UE_LOG(LogTemp, Warning, TEXT("Tile Sheet Initiated !"));

	// Clear arrays
	T_InPos.Empty();
	T_OutPos.Empty();

	// Declare locals
	int32 map_rim_x = MapSizeX + 2;
	int32 map_rim_y = MapSizeY + 2;
	int32 starting_x;
	int32 starting_y;

	// Check if size X even or odd
	if (map_rim_x % 2 == 0) {
		starting_x = (0 - (TileSize * (MapSizeX / 2)) - (TileSize / 2));
	}
	else {
		starting_x = 0 - (ceil((float)(MapSizeX / 2)) * TileSize);
	}

	// Check if size Y even or odd
	if (map_rim_y % 2 == 0) {
		starting_y = (0 - (TileSize * (MapSizeX / 2)) - (TileSize / 2));
	}
	else {
		starting_y = 0 - (ceil((float)(MapSizeX / 2)) * TileSize);
	}

	// Reset center to actor positon
	FVector starting_position((float)(starting_x), (float)(starting_y), 0.0);

	// For each Y (rows) and X (columns)
	for (size_t y = 0; y < map_rim_y; y++) {
		for (size_t x = 0; x < map_rim_x; x++) {

			// Create a position for tile
			FVector temp_vector((float)(TileSize * x), (float)(TileSize * y), 0.0);
			// Displace it by starting position
			temp_vector += starting_position;

			// Check for rim position (first and last rows || first and last columns)
			if (y == 0 || y == (map_rim_y - 1) || x == 0 || x == (map_rim_x - 1)) {
				// New outer position
				T_OutPos.Add(temp_vector);
			}
			else {
				// New inner position
				T_InPos.Add(temp_vector);
			}

		}
	}

	// Debugging
	UE_LOG(LogTemp, Warning, TEXT("Tile Sheet Created !"));
	UE_LOG(LogTemp, Warning, TEXT("%i Tiles in InPos !"), T_InPos.Num());
}

// Creates the map layout accoring to factors
void AMapGenerator::TileMapAlgorithm()
{
	UE_LOG(LogTemp, Warning, TEXT("Tile Map Generator Initiated"));

	// Declare local variables
	TArray<FVector> T_Undefined;
	TArray<FVector> T_Waiting;
	TArray<FVector> T_TempWaiting;
	TArray<FVector> AdjacentPositions;
	TArray<int32> AdjacentIndexes;
	TArray<int32> AdjacentTypes;
	int32 Defined = 0; // debugging

	// Populate arrays
	T_Undefined = T_InPos;
	T_Types.Init(-1, T_Undefined.Num()); // Everything is undefined

	// Generate and setup random starting tile
	T_StartIndex = rand() % T_Undefined.Num();
	T_StartPos = T_InPos[T_StartIndex];
	T_Types[T_StartIndex] = 1; // Set starting as playable
	T_Waiting.Add(T_StartPos); // Add starting position to waiting list
	T_Undefined.RemoveAt(T_StartIndex); // Remove from remaining list

	// Go through all remaining tiles
	bool is_undefined_tiles = true;
	while (is_undefined_tiles)
	{
		// Reset arrays
		T_TempWaiting.Empty();

		// Go through all waiting tiles
		for (size_t t = 0; t < T_Waiting.Num(); t++)
		{
			// Declare local variables
			FVector T_Position = T_Waiting[t]; // Tile position
			int32 T_Index = T_InPos.Find(T_Position);
			int32 T_Type = T_Types[T_InPos.Find(T_Position)]; // Tile type
			int32 Count_Play = 0; // Playable tiles
			int32 Count_NonPlay = 0; // Non playable tiles
			double p = 0; // Probability

			// Reset arrays
			AdjacentPositions.Empty();
			AdjacentIndexes.Empty();
			AdjacentTypes.Empty();

			// Check if surrounding tiles exists
			GetSurroundingTiles(T_Position, AdjacentIndexes, AdjacentTypes, AdjacentPositions);

			// Get each type amount
			for (int32 y : AdjacentTypes)
			{
				y == 1 ? Count_Play++ : NULL;
				y == 0 ? Count_NonPlay++ : NULL;
			}

			// Set probability, 0 == non play and 1 == play
			p = FMath::Clamp(0.5 - (0.5 / FMath::Max((double)Count_NonPlay, 1.0)) + (0.5 / FMath::Max((double)Count_Play, 1.0)), 0.0, 1.0);

			// Current tile playable ? make sure enough adjacent play tiles, if not define one randomly
			if (T_Type == 1 && AdjacentTypes.Find(-1) != INDEX_NONE && Count_Play < 2)
			{
				int32 r_index = AdjacentIndexes[AdjacentTypes.Find(-1)];
				if (T_Types[r_index] != 1) { // Make sure not already defined
					T_Types[r_index] = 1;
					T_TempWaiting.Add(T_InPos[r_index]); // Add to temp waiting list
					Defined++; // debugging
				}
			}

			// Define non defined tiles
			for (size_t i = 0; i < AdjacentIndexes.Num(); i++)
			{
				int32 index = AdjacentIndexes[i];
				int32 type = T_Types[index];
				if (type == -1)
				{
					FMath::RandRange((float)0.0, (float)1.0) > p ? T_Types[index] = 1 : T_Types[index] = 0; // Define tile according to probability
					T_TempWaiting.Add(T_InPos[index]); // Add to temp waiting list
					Defined++; // debugging
				}
			}

		}

		T_Waiting = T_TempWaiting; // Fill waiting list with temporary waiting tiles

		// Remove new waiting tiles from remaining list
		for (FVector Vector : T_TempWaiting) {
			T_Undefined.Remove(Vector);
		}
		// Check if resting list is empty
		T_Undefined.Num() >= 1 ? NULL : is_undefined_tiles = false;

	}

	UE_LOG(LogTemp, Warning, TEXT("End of while loop with %i remaining tiles !"), T_Undefined.Num());
	UE_LOG(LogTemp, Warning, TEXT("End of while loop with %i tile defined"), Defined);

	// Transfer tiles in appropriate section
	for (size_t i = 0; i < T_InPos.Num(); i++)
	{
		switch (T_Types[i])
		{
		case 0:
			T_NonPlayPos.Add(T_InPos[i]);
			break;
		case 1:
			T_PlayPos.Add(T_InPos[i]);
			break;
		}
	}

	// Select random end tile that is a minimium distance from starting point
	float Dist;
	do
	{
		int32 tempIndex = rand() % T_PlayPos.Num(); // Random index
		T_EndPos = T_PlayPos[tempIndex]; // Get position
		Dist = FVector::Dist(T_StartPos, T_EndPos); // Get distance
	} while (Dist < TileSize * 2);
	T_EndIndex = T_InPos.Find(T_EndPos); // Set index

	// Debugging
	UE_LOG(LogTemp, Warning, TEXT("Tile Map Generator Successful"));
}

void AMapGenerator::GetSurroundingTiles(FVector TilePosition, TArray<int32>& IndexArray, TArray<int32>& TypeArray, TArray<FVector>& PositionArray)
{
	FVector TopPos = TilePosition + FVector((float)(TileSize), 0.0, 0.0);
	FVector RightPos = TilePosition + FVector(0.0, (float)(TileSize), 0.0);
	FVector BottomPos = TilePosition - FVector((float)(TileSize), 0.0, 0.0);
	FVector LeftPos = TilePosition - FVector(0.0, (float)(TileSize), 0.0);
	int32 index;
	// Top
	if (T_InPos.Find(TopPos, index))
	{
		IndexArray.Add(index);
		TypeArray.Add(T_Types[index]);
		PositionArray.Add(TopPos);
	}
	// Right
	if (T_InPos.Find(RightPos, index))
	{
		IndexArray.Add(index);
		TypeArray.Add(T_Types[index]);
		PositionArray.Add(RightPos);
	}
	// Bottom
	if (T_InPos.Find(BottomPos, index))
	{
		IndexArray.Add(index);
		TypeArray.Add(T_Types[index]);
		PositionArray.Add(BottomPos);
	}
	// Left
	if (T_InPos.Find(LeftPos, index))
	{
		IndexArray.Add(index);
		TypeArray.Add(T_Types[index]);
		PositionArray.Add(LeftPos);
	}
}

// Spawns an actor
void AMapGenerator::SpawnActor(TSubclassOf<AActor> Actor, FVector Loc, FRotator Rot)
{
	FActorSpawnParameters SpawnParams;
	AActor* SpawnedActorRef = GetWorld()->SpawnActor<AActor>(Actor, Loc, Rot, SpawnParams);
}

// Spawn the inner tiles
void AMapGenerator::SpawnInnerTiles()
{
	for (size_t p = 0; p < T_PlayPos.Num(); p++)
	{
		FVector Vector = T_PlayPos[p];
		FRotator Rot(0.0, 0.0, 0.0);
		if (Vector == T_StartPos)
		{
			SpawnActor(StartingActor, Vector, Rot);
		}
		else if (Vector == T_EndPos) {
			SpawnActor(EndActor, Vector, Rot);
		}
		else if (InnerActors.Num() == 0)
		{
			UE_LOG(LogTemp, Error, TEXT("No inner actors define ! Array is empty."));
			break;
		}
		else {
			int32 random = FMath::FloorToInt(FMath::RandRange((float)0.0, (float)1.0) * InnerActors.Num());
			SpawnActor(InnerActors[random], Vector, Rot);
		}
	}
}

// Spawn the outer tiles
void AMapGenerator::SpawnOuterTiles()
{
	for (FVector Vector : T_OutPos) {
		FRotator Rot(0.0, 0.0, 0.0);
		SpawnActor(OuterActor, Vector, Rot);
	}
	for (FVector Vector : T_NonPlayPos) {
		FRotator Rot(0.0, 0.0, 0.0);
		SpawnActor(OuterActor, Vector, Rot);
	}
}

