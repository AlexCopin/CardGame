#pragma once
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
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

USTRUCT(BlueprintType)
struct FCardData : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UTexture2D> CardImage;

	UPROPERTY(EditDefaultsOnly)
	FText Name;
	UPROPERTY(EditDefaultsOnly)
	FText Description;
	UPROPERTY(EditDefaultsOnly)
	FText Flavor;
	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<ERarity> Rarity;
	UPROPERTY(EditAnywhere)
	int32 Cost;

	UPROPERTY(EditAnywhere)
	int32 Health;

	UPROPERTY(EditAnywhere)
	int32 Attack;

	UPROPERTY(EditAnywhere)
	FGameplayTagContainer Tags;
	UPROPERTY(EditDefaultsOnly)
	bool Available = true;
};