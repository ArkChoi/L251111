// Fill out your copyright notice in the Description page of Project Settings.


#include "P38Pawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "Rocket.h"

// Sets default values
AP38Pawn::AP38Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;
	Box->SetBoxExtent(FVector(46.0f, 62.0f, 10.0f));

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);

	Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left"));
	Left->SetupAttachment(Body);
	Left->SetRelativeLocation(FVector(37.f, -21.f, 1.f));

	Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right"));
	Right->SetupAttachment(Body);
	Right->SetRelativeLocation(FVector(37.f, 21.f, 1.f));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 150.0f;
	SpringArm->SocketOffset = FVector(0, 0, 50.0f);
	SpringArm->bDoCollisionTest = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(RootComponent);
	Arrow->SetRelativeLocation(FVector(70.f, 0, 0));

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MoveMent"));
	Movement->MaxSpeed = 100.f;

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_FireAsset(TEXT("/Script/EnhancedInput.InputAction'/Game/P_38Game/Input/IA_Fire.IA_Fire'"));
	if (IA_FireAsset.Succeeded())
	{
		IA_Fire = IA_FireAsset.Object;
	}
}

// Called when the game starts or when spawned
void AP38Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AP38Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddMovementInput(GetActorForwardVector());

	Left->AddLocalRotation(FRotator(0, 0, 3600.f * DeltaTime));
	Right->AddLocalRotation(FRotator(0, 0, 3600.f * DeltaTime));
}

// Called to bind functionality to input
void AP38Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* UIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (UIC)
	{
		UIC->BindAction(IA_Fire, ETriggerEvent::Triggered, this, &AP38Pawn::EnhancedFire);
	}
}

void AP38Pawn::RoketFire()
{
	this->GetWorld()->SpawnActor<ARocket>(ARocket::StaticClass(), Arrow->K2_GetComponentToWorld());
}

//
void AP38Pawn::EnhancedFire(const FInputActionValue& Value)
{
	AP38Pawn::RoketFire();
	UE_LOG(LogTemp, Warning, TEXT("Fire"));
}
