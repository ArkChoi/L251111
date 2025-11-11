// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

UCLASS()
class P38_API ATarget : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	TObjectPtr <class UBoxComponent> Box;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
	TObjectPtr <class UStaticMeshComponent> Sphere;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	TObjectPtr <class UParticleSystem> P_Explosion;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	TObjectPtr <class USoundBase> Cue_Explosion;

	UFUNCTION()
	void ProcessActorAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION(BlueprintImplementableEvent)
	void DoDesigner();

	UFUNCTION(BlueprintNativeEvent)
	void DoDesigner2();
	void DoDesigner2_Implementation(void);
};