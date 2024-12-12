#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardStructs.h"
#include "Templates/Function.h"

#include "Card.generated.h"


DECLARE_MULTICAST_DELEGATE_OneParam(FStatChanged, int);

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
	UFUNCTION(BlueprintImplementableEvent)
	void SetStyle();

	bool Replicated = false;

	/*FStatChanged OnHealthChanged;
	FStatChanged OnAttackChanged;*/

	UPROPERTY(ReplicatedUsing=OnRep_CardData, BlueprintReadOnly) 
	FCardData CardData;

	UFUNCTION()
	virtual void OnRep_CardData();

	TMap<FGameplayTag, FStatChanged> EventsStatChanged;
	UFUNCTION(BlueprintCallable)
	bool BindToStatDelegate(FGameplayTag StatTag, UObject* Listener, FName FunctionName);

	FCardStat* GetCardStat(FGameplayTag StatTag);

	UFUNCTION(BlueprintCallable)
	FCardStat GetCardStatCopy(FGameplayTag StatTag);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void Server_AddToStats(FGameplayTag StatTag, int Added);
	//Listener->GetClass()->GetFunction()
};