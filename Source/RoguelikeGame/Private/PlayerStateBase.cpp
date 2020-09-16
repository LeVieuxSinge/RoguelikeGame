// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStateBase.h"
#include "AttributeSetBase.h"
#include "EquipmentAttributeSet.h"


APlayerStateBase::APlayerStateBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	AbilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
	AttributeSetBaseComp = CreateDefaultSubobject<UAttributeSetBase>("AttributeSetBaseComp");
	EquipmentAttributeSetComp = CreateDefaultSubobject<UEquipmentAttributeSet>("EquipmentAttributeSetComp");
}

UAbilitySystemComponent* APlayerStateBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

void APlayerStateBase::AcquireAbility(TSubclassOf<UGameplayAbility> AbilityToAcquire)
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
