// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;
	Box->SetBoxExtent(FVector(50.f, 160.f, 160.f));

	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(Box);
	Sphere->SetRelativeScale3D(FVector(0.25f, 1.f, 1.f));

	Tags.Add("Target");
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	OnTakeAnyDamage.AddDynamic(this, &ATarget::ProcessActorAnyDamage);
	
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATarget::ProcessActorAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), P_Explosion, GetActorLocation());
	UGameplayStatics::SpawnSoundAtLocation(GetWorld(), Cue_Explosion, GetActorLocation());

	DoDesigner2();
	Destroy();
}

void ATarget::DoDesigner2_Implementation(void)
{
	UE_LOG(LogTemp, Warning, TEXT("Cpp Code"));
}
