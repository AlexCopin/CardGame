// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CardStructs.h"
#include "PDA_Card.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAME_API UPDA_Card : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FCardData CardData;
};
