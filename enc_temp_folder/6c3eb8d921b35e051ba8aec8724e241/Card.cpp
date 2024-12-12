#include "Card.h"
#include <Net/UnrealNetwork.h>
#include <CardGame/Include/CG_Macros.h>
#include <CardGame/GameFramework/CG_GameStateBase.h>


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

void ACard::OnRep_CardData()
{
	if (!Replicated) 
	{
		for(auto stat : CardData.Stats.CardStatsArray)
		{
			FStatChanged event;
			EventsStatChanged.Add(stat.StatTag, event);
		}
		SetStyle();
		Replicated = true;
	}
	/*FCardStat cardStat;
	CardData.Stats.FindCardStat(MAKE_TAG("Stat.Card.Attack"), cardStat);
	OnAttackChanged.Broadcast(cardStat.CurrentValue);
	CardData.Stats.FindCardStat(MAKE_TAG("Stat.Card.Health"), cardStat);
	OnHealthChanged.Broadcast(cardStat.CurrentValue);*/
	TArray<FGameplayTag> outKeys; EventsStatChanged.GetKeys(outKeys);
	for (FGameplayTag key : outKeys) 
	{
		
		auto stat = CardData.Stats.FindCardStat(key);
		EventsStatChanged[key].Broadcast(stat->CurrentValue);
	}
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, "OnRep_CardData");
}

bool ACard::BindToStatDelegate(FGameplayTag StatTag, UObject* Listener, FName FunctionName)
{
	if (auto event = EventsStatChanged.Find(StatTag))
	{
		event->AddUFunction(Listener, FunctionName);
		return true;
	}
	return false;
}

FCardStat* ACard::GetCardStat(FGameplayTag StatTag)
{
	return CardData.Stats.FindCardStat(StatTag);
}

FCardStat ACard::GetCardStatCopy(FGameplayTag StatTag)
{
	return *CardData.Stats.FindCardStat(StatTag);;
}

void ACard::Server_AddToStats_Implementation(FGameplayTag StatTag, int Added)
{
	/*FCardStat cardStat;
	FCardData dataTemp = Card->CardData;
	TArray<FCardStat> cardStats;
	for(auto stat : dataTemp.Stats.CardStatsArray)
	{
		FCardStat tempStat;
		if (stat.StatTag.MatchesTagExact(StatTag))
			tempStat.AddToValue(Added);
		cardStats.Add(tempStat);
	}*/
	FCardStat* cardStat = CardData.Stats.FindCardStat(StatTag);
	float currentValue = cardStat->CurrentValue;
	cardStat->AddToValue(Added);
	UE_LOG(LogTemp, Warning, TEXT("OldCardStat = %f  NewCardStat = %f"), currentValue, cardStat->CurrentValue);

	CardData.Stats.AddCardStat(StatTag, -2);
	FCardStat* cardStat2 = CardData.Stats.FindCardStat(StatTag);
	float currentValue2 = cardStat2->CurrentValue;
	UE_LOG(LogTemp, Warning, TEXT("OldCardStat2 = %f  NewCardStat2 = %f"), currentValue2, cardStat2->CurrentValue);
}