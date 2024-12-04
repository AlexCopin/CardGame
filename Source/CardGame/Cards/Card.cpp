#include "Card.h"
#include <Net/UnrealNetwork.h>
#include <CardGame/Include/CG_Macros.h>


ACard::ACard()
{
	SetReplicates(true);
}
void ACard::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Here we list the variables we want to replicate
	DOREPLIFETIME(ACard, CardData);
}

void ACard::BeginPlay()
{
	Super::BeginPlay();
}

void ACard::Init(const FCardData& InitCardData)
{
	CardData = InitCardData;
}

void ACard::Server_AddToStats_Implementation(FGameplayTag StatTag,int Added)
{
	CardData.Stats.FindCardStat(StatTag).AddToValue(Added);
}

void ACard::OnRep_CardData()
{
	OnAttackChanged.Broadcast(CardData.Stats.FindCardStat(MAKE_TAG("Stat.Card.Attack")).CurrentValue);
	OnHealthChanged.Broadcast(CardData.Stats.FindCardStat(MAKE_TAG("Stat.Card.Health")).CurrentValue);
}
