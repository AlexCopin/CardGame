#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardStructs.h"

#include "Card.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStatChanged, int, OldValue, int, NewValue);

UCLASS()
class CARDGAME_API ACard : public AActor
{
	GENERATED_BODY()

	ACard();
public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void Init(const FCardData& InitCardData);

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite)
	FStatChanged OnHealthChanged;
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite)
	FStatChanged OnAttackChanged;

	UFUNCTION(BlueprintCallable)
	void AddToAttack(int Added);
	UFUNCTION(BlueprintCallable)
	void AddToHealth(int Added);

	UPROPERTY(BlueprintReadOnly) 
	FCardData CardData;
};