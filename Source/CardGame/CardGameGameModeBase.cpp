// Fill out your copyright notice in the Description page of Project Settings.


#include "CardGameGameModeBase.h"
#include "GameFramework/CG_GameStateBase.h"

void ACardGameGameModeBase::UpdateGameStateInfos()
{
	if (auto GS = GetGameState<ACG_GameStateBase>())
	{
		GS->CardList = CardList;
	}
}

void ACardGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UpdateGameStateInfos();
}
