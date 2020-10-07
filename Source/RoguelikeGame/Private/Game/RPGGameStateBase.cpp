// Copyright Epic Games, Inc. All Rights Reserved.

#include "Game/RPGGameStateBase.h"

void ARPGGameStateBase::GenerateNewProceduralMap()
{
	ProceduralMap.GetDefaultObject()->Generate();
}
