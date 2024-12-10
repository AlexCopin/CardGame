#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.h"

#include "CardManager.generated.h"


UCLASS()
class CARDGAME_API ACardManager : public AActor
{
	GENERATED_BODY()

public:
	ACardManager();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CardIds)
	TArray<FName> CardIds;
	UFUNCTION()
	virtual void OnRep_CardIds();

	UPROPERTY(BlueprintReadOnly)
	TArray<TObjectPtr<ACard>> CardsList;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSubclassOf<ACard> CardClass;

	UFUNCTION(Server, Reliable)
	void Server_CreateDeck();
};