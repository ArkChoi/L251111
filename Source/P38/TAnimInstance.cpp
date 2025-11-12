// Fill out your copyright notice in the Description page of Project Settings.


#include "TAnimInstance.h"
#include "Gameframework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TMyCharacter.h"

void UTAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ACharacter* Character = Cast<ACharacter>(TryGetPawnOwner());
	if (Character)
	{
		GroundSpeed = Character->GetCharacterMovement()->Velocity.Size2D();
	}

	ATMyCharacter* OwnerCharacter = Cast<ATMyCharacter>(GetOwningActor());
	if (OwnerCharacter)
	{
		this->bIsRun = OwnerCharacter->bIsRun;
	}
}
