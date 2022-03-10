// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/HUD.h"
#include "KawaiiKarnageHud.generated.h"


UCLASS(config = Game)
class AKawaiiKarnageHud : public AHUD
{
	GENERATED_BODY()

public:
	AKawaiiKarnageHud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface
};
