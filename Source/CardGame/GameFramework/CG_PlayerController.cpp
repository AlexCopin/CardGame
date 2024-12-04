// Fill out your copyright notice in the Description page of Project Settings.


#include "CG_PlayerController.h"
#include "CG_GameStateBase.h"
#include "Kismet/GameplayStatics.h"

void ACG_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (IsLocalController()) 
	{
		GetPawn();
		auto GS = GetWorld()->GetGameState<ACG_GameStateBase>();
		CardManager = GetWorld()->SpawnActorDeferred<ACardManager>(CardManagerClass, GetPawn()->GetActorTransform(), this, GetPawn());
		CardManager->CardIds = DeckIds;
		UGameplayStatics::FinishSpawningActor(CardManager, GetPawn()->GetActorTransform());
		//
	}
}
