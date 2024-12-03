#pragma once
#include "CardStructs.h"

#include "C_CardStats.generated.h"


UCLASS()
class UC_CardStats : public UActorComponent
{
  GENERATED_BODY()
protected:
  UPROPERTY(BlueprintReadWrite)
  FCardStats Stats;
public:

	virtual void BeginPlay() override;
  
	/*UPROPERTY(BlueprintAssignable, BlueprintReadWrite)
	FStatChanged OnHealthChanged;
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite)
	FStatChanged OnAttackChanged;

	UFUNCTION(BlueprintCallable)
	void AddToAttack();
	UFUNCTION(BlueprintCallable)
	void AddToHealth();*/
};