// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class P38_API ATPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATPlayerController();

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<class UInputMappingContext> InputMapping;

	virtual void OnPossess(APawn* aPawn) override;
	void OnUnPossess() override;
};
