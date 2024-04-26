// Copyright Epic Games, Inc. All Rights Reserved.

#include "CozyScapeGameMode.h"
#include "CozyScapeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACozyScapeGameMode::ACozyScapeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
