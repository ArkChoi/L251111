// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "P38PlayerController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class P38_API AP38PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AP38PlayerController();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> InputMapping;

	virtual void OnPossess(APawn* aPawn) override;
	void OnUnPossess() override;
};
