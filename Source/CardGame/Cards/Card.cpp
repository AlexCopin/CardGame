#include "Card.h"


ACard::ACard()
{
	SetReplicates(true);
}

void ACard::BeginPlay()
{
	Super::BeginPlay();
}

void ACard::Init(const FCardData& InitCardData)
{
	CardData = InitCardData;
}

void ACard::AddToAttack(int Added)
{
	int oldAttack = CardData.Stats.CurrentAttack;
	CardData.Stats.CurrentAttack += Added;
	OnAttackChanged.Broadcast(oldAttack, CardData.Stats.CurrentAttack);
}
void ACard::AddToHealth(int Added)
{
	int oldHealth = CardData.Stats.CurrentHealth;
	CardData.Stats.CurrentHealth += Added;
	OnAttackChanged.Broadcast(oldHealth, CardData.Stats.CurrentHealth);
}
