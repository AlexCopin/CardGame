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

void ACard::Server_AddToStats_Implementation(FGameplayTag StatTag,int Added)
{
	FCardStat cardStat;
	CardData.Stats.FindCardStat(StatTag, cardStat);
	cardStat.AddToValue(Added);
}

void ACard::Editor_AddToStats(FGameplayTag StatTag, int Added)
{
	Server_AddToStats(StatTag, Added);
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
		FCardStat cardStat;
		CardData.Stats.FindCardStat(key, cardStat);
		EventsStatChanged[key].Broadcast(cardStat.CurrentValue);
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

FCardStat ACard::GetCardStat(FGameplayTag StatTag)
{
	FCardStat cardStat;
	CardData.Stats.FindCardStat(StatTag, cardStat);
	return cardStat;
}
