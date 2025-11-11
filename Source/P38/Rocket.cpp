// Fill out your copyright notice in the Description page of Project Settings.


#include "Rocket.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

#include "Target.h"

// Sets default values
ARocket::ARocket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;
	Box->SetBoxExtent(FVector(30.f, 10.f, 10.f));

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	Body->SetupAttachment(Box);
	Body->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FQuat(FRotator(-90.0f, 0.0f, 0.0f)));
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->InitialSpeed = 200.f;
	ProjectileMovement->MaxSpeed = 200.f;
	ProjectileMovement->ProjectileGravityScale = 0.f;
	
}

// Called when the game starts or when spawned
void ARocket::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(3.f);

	OnActorBeginOverlap.AddDynamic(this, &ARocket::ProcessActorBeginOverlap);
}

// Called every frame
void ARocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARocket::ProcessActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	UGameplayStatics::ApplyDamage(
		OtherActor,
		10.0f,
		UGameplayStatics::GetPlayerController(GetWorld(), 0),
		this,
		nullptr
	);

	if (ATarget* Target = Cast<ATarget>(OtherActor))
	{
		Destroy();
	}
}

