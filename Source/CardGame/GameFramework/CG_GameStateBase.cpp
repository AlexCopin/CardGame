// Fill out your copyright notice in the Description page of Project Settings.
#include "CG_GameStateBase.h"
#include <Net/UnrealNetwork.h>

void ACG_GameStateBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACG_GameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACG_GameStateBase, CardList);
}
