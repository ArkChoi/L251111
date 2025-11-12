// Fill out your copyright notice in the Description page of Project Settings.


#include "TMyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ATMyCharacter::ATMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SocketOffset = FVector(0, 0, 0);
	SpringArm->bDoCollisionTest = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight()));
	GetMesh()->SetRelativeRotation(FRotator(0, -90.f, 0));
}

// Called when the game starts or when spawned
void ATMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATMyCharacter::Move(float Forward, float Right)
{
	//카메라 꺽는 방향으로 가는거
	const FRotator CameraRotation = GetController()->GetControlRotation();
	const FRotator YawRotation = FRotator( 0, CameraRotation.Yaw , 0 );
	const FRotator YawRollRotation = FRotator(0, CameraRotation.Yaw, CameraRotation.Roll);
	
	const FVector ForwardVector = UKismetMathLibrary::GetForwardVector(YawRotation);
	AddMovementInput(ForwardVector, Forward);

	//Right 구현
	const FVector RightVector = UKismetMathLibrary::GetRightVector(YawRollRotation);
	AddMovementInput(RightVector, Right);

	//구형 코드
	//AddMovementInput(FVector(Forward, Rigjt, 0));
}

void ATMyCharacter::Look(float Pitch, float Yaw)
{
	//AddActorLocalRotation(FRotator(Pitch, Yaw, 0) * 360.f * UGameplayStatics::GetWorldDeltaSeconds(GetWorld()));
	AddControllerPitchInput(Pitch);
	AddControllerYawInput(Yaw);
}

void ATMyCharacter::Run(float Forward, float Right)
{
	//카메라 꺽는 방향으로 가는거
	const FRotator CameraRotation = GetController()->GetControlRotation();
	const FRotator YawRotation = FRotator(0, CameraRotation.Yaw, 0);
	const FRotator YawRollRotation = FRotator(0, CameraRotation.Yaw, CameraRotation.Roll);

	const FVector ForwardVector = UKismetMathLibrary::GetForwardVector(YawRotation);
	AddMovementInput(ForwardVector, Forward);

	//Right 구현
	const FVector RightVector = UKismetMathLibrary::GetRightVector(YawRollRotation);
	AddMovementInput(RightVector, Right);
	//구형 코드
	//AddMovementInput(FVector(Forward, Rigjt, 0));
	GetCharacterMovement()->
}

void ATMyCharacter::RunTrigger()
{
	bIsRun = (!bIsRun);
}
