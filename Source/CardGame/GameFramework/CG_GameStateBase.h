// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"

#include "CG_GameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAME_API ACG_GameStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:
	UPROPERTY(Replicated, EditInstanceOnly, BlueprintReadOnly)
	TObjectPtr<UDataTable> CardList;

	UFUNCTION()
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;
	
};
