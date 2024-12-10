#include "CardManager.h"
#include <CardGame/GameFramework/CG_GameStateBase.h>
#include "CardStructs.h"
#include "Kismet/GameplayStatics.h"
#include <Net/UnrealNetwork.h>

ACardManager::ACardManager()
{
	SetReplicates(true);
}
void ACardManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Here we list the variables we want to replicate
	DOREPLIFETIME(ACardManager, CardIds);
}

void ACardManager::BeginPlay()
{
	Super::BeginPlay();
	//To remove if dedicated server
	/*if (GetNetMode() == ENetMode::NM_ListenServer)
		Server_CreateDeck();*/
}
void ACardManager::OnRep_CardIds()
{
	Server_CreateDeck();
}


void ACardManager::Server_CreateDeck_Implementation()
{
	if(auto GS = GetWorld()->GetGameState<ACG_GameStateBase>())
	{
		if(ensure(CardClass))
		{
			for (int i = 0; i < CardIds.Num(); i++)
			{
				FCardData cardData = *GS->CardList->FindRow<FCardData>(CardIds[i], "CardId");
				FTransform cardTransform = GetActorTransform();
				FTransform newTransform = cardTransform;
				FVector offset{ 10,0,0 };
				newTransform.SetLocation(newTransform.GetLocation() + offset * i);
				/*auto card = GetWorld()->SpawnActorDeferred<ACard>(CardClass, newTransform, GetOwner(), GetInstigator());
				card->Init(cardData);
				UGameplayStatics::FinishSpawningActor(card, newTransform);*/
				FActorSpawnParameters params;
				params.Owner = GetOwner();
				params.Instigator = GetInstigator();
				auto card = GetWorld()->SpawnActor<ACard>(CardClass, newTransform, params);
				card->Init(cardData);
				CardsList.AddUnique(card);
			}
		}
	}
}
