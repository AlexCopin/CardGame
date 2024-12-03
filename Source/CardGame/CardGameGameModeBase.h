// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CardGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAME_API ACardGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UDataTable> CardList;
};
