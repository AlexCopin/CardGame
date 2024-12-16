#pragma once
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include <CardGame/AttributeSets/AttributeSet_Card.h>

#include "CardStructs.generated.h"

class ACard;


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
UENUM(BlueprintType)
enum EInteractionType : uint8
{
	Buff UMETA(DisplayName = "Buff"),
	Debuff UMETA(DisplayName = "Debuff"),
	Attack UMETA(DisplayName = "Attack"),
};

USTRUCT(BlueprintType)
struct FCardStat
{
	GENERATED_BODY()
	FCardStat()
	{
		CurrentValue = InitialValue;
	}
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag StatTag;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float CurrentValue;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float InitialValue;

	float AddToValue(float Added) { CurrentValue += Added; return CurrentValue; }
};
USTRUCT(BlueprintType)
struct FCardStats
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	TArray<FCardStat> CardStatsArray;
	UPROPERTY(EditDefaultsOnly)
	FGameplayTagContainer InitialTags;
	UPROPERTY(EditInstanceOnly)
	FGameplayTagContainer CurrentTags;

	FCardStat* FindCardStat(FGameplayTag CardTag)
	{
		/*for (auto& cardStat : CardStatsArray)
		{
			if (cardStat.StatTag.MatchesTagExact(CardTag))
			{
				OutCardStat = cardStat;
				return;
			}
		}*/
		return CardStatsArray.FindByPredicate([&](const FCardStat& item)
			{
				return item.StatTag == CardTag;
			});
	}
	void AddCardStat(FGameplayTag CardTag, float Added)
	{
		FCardStat* cardTag = CardStatsArray.FindByPredicate([&](const FCardStat& item)
			{
				return item.StatTag == CardTag;
			});
		cardTag->AddToValue(Added);
		/*for (auto& cardStat : CardStatsArray)
		{
			if (cardStat.StatTag.MatchesTagExact(CardTag))
			{
				cardStat.AddToValue(Added);
				return;
			}
		}*/
	}

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

USTRUCT(BlueprintType)
struct FCardInteraction
{
	GENERATED_BODY()
	FCardInteraction() = default;
	FCardInteraction(uint32 IdInstigator, uint32 IdReceiver, FGameplayTag Tag, EInteractionType InteractionType, float Value)
		: InstigatorId(IdInstigator), ReceiverId(IdReceiver), StatTag(Tag), Type(InteractionType), Added(Value) {}


	uint32 InstigatorId;
	uint32 ReceiverId;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag StatTag;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TEnumAsByte<EInteractionType> Type;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Added;
};

USTRUCT(BlueprintType)
struct FCardId
{
	GENERATED_BODY()
	uint32 Id;
	ACard* Card;
};

