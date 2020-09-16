// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "EquipmentAttributeSet.generated.h"


UCLASS()
class ROGUELIKEGAME_API UEquipmentAttributeSet : public UAttributeSet
{
	GENERATED_BODY()


public:
	UEquipmentAttributeSet();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandVFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandMainAbilityID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandOffAbilityID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandAttackSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandPhysicalDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandFireDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandColdDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandLightningDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandInnateModifierID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandModifier1ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandModifier2ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandModifier3ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandModifier4ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandModifier5ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData MainHandIsTwoHand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MainHand")
		FGameplayAttributeData CharacterStance;
};