// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"
#include "EquipmentItem.generated.h"


class UEquipmentItemAttributeSet;

UCLASS()
class ROGUELIKEGAME_API AEquipmentItem : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEquipmentItem();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "EquipmentBase")
		UAbilitySystemComponent* AbilitySystemComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "EquipmentBase")
		UEquipmentItemAttributeSet* EquipmentItemAttributeSetComp;

	UFUNCTION(BlueprintCallable, Category = "EquipmentBase")
		void AcquireAbility(TSubclassOf<UGameplayAbility> AbilityToAcquire);

	UFUNCTION(BlueprintCallable, Category = "EquipmentBase")
		void CreateGameplayDataStructure(float NewValue, FGameplayAttributeData& jkb);

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
