// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "EquipmentItemAttributeSet.generated.h"


UCLASS()
class ROGUELIKEGAME_API UEquipmentItemAttributeSet : public UAttributeSet
{
	GENERATED_BODY()


public:
	UEquipmentItemAttributeSet();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemVFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemMainAbilityID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemOffAbilityID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemAttackSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemPhysicalDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemFireDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemColdDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemLightningDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemInnateModifierID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemModifier1ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemModifier2ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemModifier3ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemModifier4ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemModifier5ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData EquipmentItemIsTwoHand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentItem")
		FGameplayAttributeData CharacterStance;

};
