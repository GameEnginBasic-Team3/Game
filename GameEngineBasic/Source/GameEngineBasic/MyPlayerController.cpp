// Fill out your copyright notice in the Description page of Project Settings.
// 2023105415 ±è¼öÀº

#include "MyPlayerController.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "GameFramework/Character.h"
#include "UObject/ConstructorHelpers.h"
#include "EngineUtils.h"

AMyPlayerController::AMyPlayerController()
{
	Index = 0;
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<ACharacter> It(GetWorld()); It; ++It)
	{
		Characters.Add(*It);
	}

	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		this,
		&AMyPlayerController::PossessNextCharacter,
		2.0f,
		true
	);
}

void AMyPlayerController::PossessNextCharacter()
{
	if (Characters.Num() > 0)
	{
		Possess(Characters[Index]);
		Index = (Index + 1) % Characters.Num();
	}
}

