// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "RoguelikeGame.h"
#include "GameFramework/GameStateBase.h"
#include "Map/ProceduralMap.h"
#include "RPGGameStateBase.generated.h"

/** Base class for GameMode, should be blueprinted */
UCLASS()
class ROGUELIKEGAME_API ARPGGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	/** Constructor */
	ARPGGameStateBase() {}

	UPROPERTY(EditDefaultsOnly, Category = "Map")
	TSubclassOf<UProceduralMap> ProceduralMap;

	UFUNCTION(BlueprintCallable)
	void GenerateNewProceduralMap();

};

