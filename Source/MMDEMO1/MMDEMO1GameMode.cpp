// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "MMDEMO1.h"
#include "MMDEMO1GameMode.h"
#include "MMDEMO1Character.h"

AMMDEMO1GameMode::AMMDEMO1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
