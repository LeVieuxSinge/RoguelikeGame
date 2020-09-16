// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "EquipmentModifierAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class ROGUELIKEGAME_API UEquipmentModifierAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	


public:
	UEquipmentModifierAttributeSet();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
		FGameplayAttributeData Modifier1ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
		FGameplayAttributeData Modifier2ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
		FGameplayAttributeData Modifier3ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
		FGameplayAttributeData Modifier4ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
		FGameplayAttributeData Modifier5ID;

};