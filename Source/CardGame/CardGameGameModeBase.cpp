// Fill out your copyright notice in the Description page of Project Settings.


#include "CardGameGameModeBase.h"
#include "GameFramework/CG_GameStateBase.h"
#include "GameFramework/CG_PlayerController.h"
#include "Algo/RandomShuffle.h"

void ACardGameGameModeBase::UpdateGameStateInfos()
{
	if (auto GS = GetGameState<ACG_GameStateBase>())
	{
		GS->CardList = CardList;
	}
}

void ACardGameGameModeBase::PostLogin(APlayerController* PC)
{
	Super::PostLogin(PC);
	if(auto castedPC = Cast<ACG_PlayerController>(PC))
	{
		//castedPC->Init();
		FActorSpawnParameters params;
		params.Owner = PC;
		params.Instigator = PC->GetPawn();
		castedPC->CardManager = GetWorld()->SpawnActor<ACardManager>(castedPC->CardManagerClass, castedPC->GetPawn()->GetActorTransform(), params);
		auto copyArray = castedPC->DeckIds;
		Algo::RandomShuffle(copyArray);
		castedPC->CardManager->CardIds = copyArray;
		GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, "PostLogin");
	}
}

void ACardGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UpdateGameStateInfos();
}
