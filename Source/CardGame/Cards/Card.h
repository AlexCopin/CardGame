#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardStructs.h"

#include "Card.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStatChanged, int, NewValue);

UCLASS()
class CARDGAME_API ACard : public AActor
{
	GENERATED_BODY()

	ACard();
public:
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	UFUNCTION(BlueprintCallable)
	void Init(const FCardData& InitCardData);

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite)
	FStatChanged OnHealthChanged;
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite)
	FStatChanged OnAttackChanged;

	UFUNCTION(Server, Reliable)
	void Server_AddToStats(FGameplayTag StatTag, int Added);

	UPROPERTY(ReplicatedUsing=OnRep_CardData) 
	FCardData CardData;

	UFUNCTION()
	virtual void OnRep_CardData();
};