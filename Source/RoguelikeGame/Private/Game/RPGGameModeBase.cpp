// Copyright Epic Games, Inc. All Rights Reserved.

#include "Game/RPGGameModeBase.h"
#include "Game/RPGGameStateBase.h"
#include "Character/RPGPlayerControllerBase.h"

ARPGGameModeBase::ARPGGameModeBase()
{
	GameStateClass = ARPGGameStateBase::StaticClass();
	PlayerControllerClass = ARPGPlayerControllerBase::StaticClass();
}