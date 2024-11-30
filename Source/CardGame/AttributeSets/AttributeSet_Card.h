#pragma once
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"

#include "AttributeSet_Card.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class CARDGAME_API UAttributeSet_Card : public UAttributeSet
{
  GENERATED_BODY()
public:
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Cost;
	ATTRIBUTE_ACCESSORS(UAttributeSet_Card, Cost);

  UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayAttributeData HP;
	ATTRIBUTE_ACCESSORS(UAttributeSet_Card, HP);

  UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayAttributeData MaxHP;
	ATTRIBUTE_ACCESSORS(UAttributeSet_Card, MaxHP);
};