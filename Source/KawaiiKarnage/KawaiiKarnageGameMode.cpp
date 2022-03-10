// Copyright Epic Games, Inc. All Rights Reserved.

#include "KawaiiKarnageGameMode.h"
#include "KawaiiKarnagePawn.h"
#include "KawaiiKarnageHud.h"

AKawaiiKarnageGameMode::AKawaiiKarnageGameMode()
{
	DefaultPawnClass = AKawaiiKarnagePawn::StaticClass();
	HUDClass = AKawaiiKarnageHud::StaticClass();
}
