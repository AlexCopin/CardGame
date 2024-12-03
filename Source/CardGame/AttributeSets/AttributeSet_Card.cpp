#include "AttributeSet_Card.h"

void UAttributeSet_Card::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	/*if(Attribute == GetHPAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, GetMaxHP());
	}*/
}
