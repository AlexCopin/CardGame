#pragma once
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include <CardGame/AttributeSets/AttributeSet_Card.h>

#include "CardStructs.generated.h"

UENUM(BlueprintType)
enum ERarity : uint8
{
	Common UMETA(DisplayName = "Common"),
	Uncommon UMETA(DisplayName = "Uncommon"),
	Rare UMETA(DisplayName = "Rare"),
	Epic UMETA(DisplayName = "Epic"),
	Legendary UMETA(DisplayName = "Legendary"),
	Mythic UMETA(DisplayName = "Mythic")
};
UENUM(BlueprintType)
enum EFamily : uint8
{
	Troll UMETA(DisplayName = "Troll"),
	Shade UMETA(DisplayName = "Shade"),
	Golem UMETA(DisplayName = "Golem"),
	Arrakoa UMETA(DisplayName = "Arrakoa")
};

USTRUCT(BlueprintType)
struct FCardStats
{
	GENERATED_BODY()
	FCardStats() {
		CurrentCost = InitialCost;
		CurrentAttack = InitialAttack;
		CurrentHealth = InitialHealth;
		CurrentTags = InitialTags;
	}
public:
	UPROPERTY(EditDefaultsOnly)
	int InitialCost;
	UPROPERTY(EditInstanceOnly)
	int CurrentCost;
	UPROPERTY(EditDefaultsOnly)
	int InitialAttack;
	UPROPERTY(EditInstanceOnly)
	int CurrentAttack;
	UPROPERTY(EditDefaultsOnly)
	int InitialHealth;
	UPROPERTY(EditInstanceOnly)
	int CurrentHealth;
	UPROPERTY(EditDefaultsOnly)
	FGameplayTagContainer InitialTags;
	UPROPERTY(EditInstanceOnly)
	FGameplayTagContainer CurrentTags;

};
USTRUCT(BlueprintType)
struct FCardData : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FString Id;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UMaterial> CardImage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Description;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Flavor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TEnumAsByte<ERarity> Rarity;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TEnumAsByte<EFamily> Family;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FCardStats Stats;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool Available = true;
};