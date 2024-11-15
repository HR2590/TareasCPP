// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tarea1_CPPGameMode.h"
#include "Tarea1_CPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATarea1_CPPGameMode::ATarea1_CPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
