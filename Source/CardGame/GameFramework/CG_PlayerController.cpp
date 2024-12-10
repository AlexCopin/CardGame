// Fill out your copyright notice in the Description page of Project Settings.


#include "CG_PlayerController.h"
#include "CG_GameStateBase.h"
#include "Kismet/GameplayStatics.h"
#include <Net/UnrealNetwork.h>

void ACG_PlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ACG_PlayerController::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}

void ACG_PlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACG_PlayerController, CardManager);
}

void ACG_PlayerController::Init()
{
	/*CardManager = GetWorld()->SpawnActorDeferred<ACardManager>(CardManagerClass, GetPawn()->GetActorTransform(), this, GetPawn());
	UGameplayStatics::FinishSpawningActor(CardManager, GetPawn()->GetActorTransform());
	CardManager->CardIds = DeckIds;*/
}
