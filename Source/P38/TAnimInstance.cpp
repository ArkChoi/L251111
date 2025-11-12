// Fill out your copyright notice in the Description page of Project Settings.


#include "TAnimInstance.h"
#include "Gameframework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TMyCharacter.h"

void UTAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ATMyCharacter* Character = Cast<ATMyCharacter>(TryGetPawnOwner());//여기서 Try를 쓰는 이유는 각 따로 CPU 사용하다보니 한쪽만 죽고 다른 한쪽은 안죽었을수도 있다보니 Try로 한번 조건을 거치는 것이다.
	if (Character)
	{
		GroundSpeed = Character->GetCharacterMovement()->Velocity.Size2D();
		this->bIsRun = Character->bIsRun;
	}

}
