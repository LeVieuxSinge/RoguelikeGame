// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "RoguelikeGame.h"
#include "GameFramework/GameModeBase.h"
#include "RPGGameModeBase.generated.h"

/** Base class for GameMode, should be blueprinted */
UCLASS()
class ROGUELIKEGAME_API ARPGGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	/** Constructor */
	ARPGGameModeBase();
};

