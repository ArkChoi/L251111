// Fill out your copyright notice in the Description page of Project Settings.


#include "TGameMode.h"
#include "TMyCharacter.h"
#include "TPlayerController.h"

ATGameMode::ATGameMode()
{
	DefaultPawnClass = ATMyCharacter::StaticClass();
	PlayerControllerClass = ATPlayerController::StaticClass();
}
