// Fill out your copyright notice in the Description page of Project Settings.


#include "Tommy/EquipmentItem.h"
#include "Tommy/EquipmentItemAttributeSet.h"


// Sets default values
AEquipmentItem::AEquipmentItem()
{
	AbilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
	EquipmentItemAttributeSetComp = CreateDefaultSubobject<UEquipmentItemAttributeSet>("EquipmentItemAttributeSetComp");
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

}

UAbilitySystemComponent* AEquipmentItem::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

void AEquipmentItem::AcquireAbility(TSubclassOf<UGameplayAbility> AbilityToAcquire)
{
	if (AbilitySystemComp)
	{
		if (HasAuthority() && AbilityToAcquire)
		{
			FGameplayAbilitySpecDef SpecDef = FGameplayAbilitySpecDef();
			SpecDef.Ability = AbilityToAcquire;
			FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(SpecDef, 1);
			AbilitySystemComp->GiveAbility(AbilitySpec);
		}
		AbilitySystemComp->InitAbilityActorInfo(this, this);
	}
}

void AEquipmentItem::CreateGameplayDataStructure(float NewValue, FGameplayAttributeData& jkb)
{
	jkb = FGameplayAttributeData(NewValue);
}



// Called when the game starts or when spawned
void AEquipmentItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEquipmentItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

