// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <CardGame/Cards/CardManager.h>
#include "CG_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAME_API ACG_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	void OnRep_PlayerState() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FName> DeckIds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ACardManager> CardManagerClass;

	UPROPERTY(Replicated)
	TObjectPtr<ACardManager> CardManager;


	UFUNCTION()
	void Init();

};
