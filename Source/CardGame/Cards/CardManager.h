#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "CardManager.generated.h"


UCLASS()
class CARDGAME_API ACardManager : public AActor
{
	GENERATED_BODY()

public:
	ACardManager();
	UPROPERTY(BlueprintReadOnly)
	TArray<FName> CardIds;
};