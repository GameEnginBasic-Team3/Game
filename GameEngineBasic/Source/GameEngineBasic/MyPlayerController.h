// Fill out your copyright notice in the Description page of Project Settings.
// 2023105415 ±è¼öÀº

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEENGINEBASIC_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	AMyPlayerController();

protected:
	virtual void BeginPlay() override;

private:
	void PossessNextCharacter();
	TArray<ACharacter*> Characters;
	FTimerHandle TimerHandle;
	int32 Index;

};
