#include "Card.h"

void ACard::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("CardASC");
}
