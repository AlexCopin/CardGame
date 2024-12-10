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

	UFUNCTION(Server, Reliable)
	void Server_AddToStats(FGameplayTag StatTag, int Added);
	UFUNCTION(CallInEditor)
	void Editor_AddToStats(FGameplayTag StatTag, int Added);

	UPROPERTY(ReplicatedUsing=OnRep_CardData, BlueprintReadOnly) 
	FCardData CardData;

	UFUNCTION()
	virtual void OnRep_CardData();

	//TryCalls

	TMap<FGameplayTag, FStatChanged> EventsStatChanged;
	UFUNCTION(BlueprintCallable)
	bool BindToStatDelegate(FGameplayTag StatTag, UObject* Listener, FName FunctionName);

	UFUNCTION(BlueprintCallable)
	FCardStat GetCardStat(FGameplayTag StatTag);
	//Listener->GetClass()->GetFunction()
};