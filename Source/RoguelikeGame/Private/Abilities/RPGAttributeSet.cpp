// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/RPGAttributeSet.h"
#include "Abilities/RPGAbilitySystemComponent.h"
#include "Character/RPGCharacterBase.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

URPGAttributeSet::URPGAttributeSet()
	: Health(1.f)
	, MaxHealth_Initial(1.f)
	, MaxHealth_Initial_Multiplier(1.f)
	, MaxHealth_Flat_Additive(0.f)
	, MaxHealth_Increase_Multiplier(0.f)
	, MaxHealth_Exponential_Multiplier(1.f)
	, MaxHealth(1.f)
	, Damage_Initial(1.f)
	, Damage_Initial_Multiplier(1.f)
	, Damage_Increase_Multiplier(0.f)
	, Damage_Exponential_Multiplier(1.f)
	, AttackDamage_Initial(1.f)
	, AttackDamage_Initial_Multiplier(1.f)
	, AttackDamage_Increase_Multiplier(0.f)
	, AttackDamage_Exponential_Multiplier(1.f)
	, SpellDamage_Initial(1.f)
	, SpellDamage_Initial_Multiplier(1.f)
	, SpellDamage_Increase_Multiplier(0.f)
	, SpellDamage_Exponential_Multiplier(1.f)
	, PhysicalDamage_Initial(1.f)
	, PhysicalDamage_Initial_Multiplier(1.f)
	, PhysicalDamage_Increase_Multiplier(0.f)
	, PhysicalDamage_Exponential_Multiplier(1.f)
	, ElementalDamage_Initial(1.f)
	, ElementalDamage_Initial_Multiplier(1.f)
	, ElementalDamage_Increase_Multiplier(0.f)
	, ElementalDamage_Exponential_Multiplier(1.f)
	, FireDamage_Initial(1.f)
	, FireDamage_Initial_Multiplier(1.f)
	, FireDamage_Increase_Multiplier(0.f)
	, FireDamage_Exponential_Multiplier(1.f)
	, FreezeDamage_Initial(1.f)
	, FreezeDamage_Initial_Multiplier(1.f)
	, FreezeDamage_Increase_Multiplier(0.f)
	, FreezeDamage_Exponential_Multiplier(1.f)
	, ElectricDamage_Initial(1.f)
	, ElectricDamage_Initial_Multiplier(1.f)
	, ElectricDamage_Increase_Multiplier(0.f)
	, ElectricDamage_Exponential_Multiplier(1.f)
	, BashDamage_Initial(1.f)
	, BashDamage_Initial_Multiplier(1.f)
	, BashDamage_Increase_Multiplier(0.f)
	, BashDamage_Exponential_Multiplier(1.f)
	, SlashDamage_Initial(1.f)
	, SlashDamage_Initial_Multiplier(1.f)
	, SlashDamage_Increase_Multiplier(0.f)
	, SlashDamage_Exponential_Multiplier(1.f)
	, StabDamage_Initial(1.f)
	, StabDamage_Initial_Multiplier(1.f)
	, StabDamage_Increase_Multiplier(0.f)
	, StabDamage_Exponential_Multiplier(1.f)
	, AttackPower(1.0f)
	, DefensePower(1.0f)
	, MoveSpeed(1.0f)
	, Damage(0.0f)
{
}

void URPGAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(URPGAttributeSet, Health);
	DOREPLIFETIME(URPGAttributeSet, MaxHealth_Initial);
	DOREPLIFETIME(URPGAttributeSet, MaxHealth_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, MaxHealth_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, MaxHealth_Increase_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, MaxHealth_Exponential_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, MaxHealth);
	DOREPLIFETIME(URPGAttributeSet, Damage_Initial);
	DOREPLIFETIME(URPGAttributeSet, Damage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, Damage_Increase_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, Damage_Exponential_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AttackDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, AttackDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AttackDamage_Increase_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AttackDamage_Exponential_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, SpellDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, SpellDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, SpellDamage_Increase_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, SpellDamage_Exponential_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, PhysicalDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, PhysicalDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, PhysicalDamage_Increase_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, PhysicalDamage_Exponential_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElementalDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, ElementalDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElementalDamage_Increase_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElementalDamage_Exponential_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FireDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, FireDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FireDamage_Increase_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FireDamage_Exponential_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FreezeDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, FreezeDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FreezeDamage_Increase_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FreezeDamage_Exponential_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElectricDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, ElectricDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElectricDamage_Increase_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElectricDamage_Exponential_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, BashDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, BashDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, BashDamage_Increase_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, BashDamage_Exponential_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, SlashDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, SlashDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, SlashDamage_Increase_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, SlashDamage_Exponential_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, StabDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, StabDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, StabDamage_Increase_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, StabDamage_Exponential_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AttackPower);
	DOREPLIFETIME(URPGAttributeSet, DefensePower);
	DOREPLIFETIME(URPGAttributeSet, MoveSpeed);
}

void URPGAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Health, OldValue);
}

void URPGAttributeSet::OnRep_MaxHealth_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxHealth_Initial, OldValue);
}

void URPGAttributeSet::OnRep_MaxHealth_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxHealth_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_MaxHealth_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxHealth_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_MaxHealth_Increase_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxHealth_Increase_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_MaxHealth_Exponential_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxHealth_Exponential_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxHealth, OldValue);
}

void URPGAttributeSet::OnRep_Damage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Damage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_Damage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Damage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_Damage_Increase_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Damage_Increase_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_Damage_Exponential_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Damage_Exponential_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AttackDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AttackDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_AttackDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AttackDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AttackDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AttackDamage_Increase_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AttackDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AttackDamage_Exponential_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_SpellDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, SpellDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_SpellDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, SpellDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_SpellDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, SpellDamage_Increase_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_SpellDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, SpellDamage_Exponential_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalDamage_Increase_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalDamage_Exponential_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElementalDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_ElementalDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElementalDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalDamage_Increase_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElementalDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalDamage_Exponential_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FireDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_FireDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FireDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireDamage_Increase_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FireDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireDamage_Exponential_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FreezeDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_FreezeDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FreezeDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeDamage_Increase_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FreezeDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeDamage_Exponential_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElectricDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_ElectricDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElectricDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricDamage_Increase_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElectricDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricDamage_Exponential_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_BashDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, BashDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_BashDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, BashDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_BashDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, BashDamage_Increase_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_BashDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, BashDamage_Exponential_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_SlashDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, SlashDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_SlashDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, SlashDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_SlashDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, SlashDamage_Increase_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_SlashDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, SlashDamage_Exponential_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_StabDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, StabDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_StabDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, StabDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_StabDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, StabDamage_Increase_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_StabDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, StabDamage_Exponential_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AttackPower, OldValue);
}

void URPGAttributeSet::OnRep_DefensePower(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, DefensePower, OldValue);
}

void URPGAttributeSet::OnRep_MoveSpeed(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MoveSpeed, OldValue);
}

void URPGAttributeSet::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty)
{
	UAbilitySystemComponent* AbilityComp = GetOwningAbilitySystemComponent();
	const float CurrentMaxValue = MaxAttribute.GetCurrentValue();
	if (!FMath::IsNearlyEqual(CurrentMaxValue, NewMaxValue) && AbilityComp)
	{
		// Change current value to maintain the current Val / Max percent
		const float CurrentValue = AffectedAttribute.GetCurrentValue();
		float NewDelta = (CurrentMaxValue > 0.f) ? (CurrentValue * NewMaxValue / CurrentMaxValue) - CurrentValue : NewMaxValue;

		AbilityComp->ApplyModToAttributeUnsafe(AffectedAttributeProperty, EGameplayModOp::Additive, NewDelta);
	}
}

void URPGAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	// This is called whenever attributes change, so for max health/mana we want to scale the current totals to match
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetMaxHealthAttribute())
	{
		AdjustAttributeForMaxChange(Health, MaxHealth, NewValue, GetHealthAttribute());
	}
	
}

void URPGAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	UAbilitySystemComponent* Source = Context.GetOriginalInstigatorAbilitySystemComponent();
	const FGameplayTagContainer& SourceTags = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();

	// Compute the delta between old and new, if it is available
	float DeltaValue = 0;
	if (Data.EvaluatedData.ModifierOp == EGameplayModOp::Type::Additive)
	{
		// If this was additive, store the raw delta value to be passed along later
		DeltaValue = Data.EvaluatedData.Magnitude;
	}

	// Get the Target actor, which should be our owner
	AActor* TargetActor = nullptr;
	AController* TargetController = nullptr;
	ARPGCharacterBase* TargetCharacter = nullptr;
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		TargetCharacter = Cast<ARPGCharacterBase>(TargetActor);
	}

	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		// Get the Source actor
		AActor* SourceActor = nullptr;
		AController* SourceController = nullptr;
		ARPGCharacterBase* SourceCharacter = nullptr;
		if (Source && Source->AbilityActorInfo.IsValid() && Source->AbilityActorInfo->AvatarActor.IsValid())
		{
			SourceActor = Source->AbilityActorInfo->AvatarActor.Get();
			SourceController = Source->AbilityActorInfo->PlayerController.Get();
			if (SourceController == nullptr && SourceActor != nullptr)
			{
				if (APawn* Pawn = Cast<APawn>(SourceActor))
				{
					SourceController = Pawn->GetController();
				}
			}

			// Use the controller to find the source pawn
			if (SourceController)
			{
				SourceCharacter = Cast<ARPGCharacterBase>(SourceController->GetPawn());
			}
			else
			{
				SourceCharacter = Cast<ARPGCharacterBase>(SourceActor);
			}

			// Set the causer actor based on context if it's set
			if (Context.GetEffectCauser())
			{
				SourceActor = Context.GetEffectCauser();
			}
		}

		// Try to extract a hit result
		FHitResult HitResult;
		if (Context.GetHitResult())
		{
			HitResult = *Context.GetHitResult();
		}

		// Store a local copy of the amount of damage done and clear the damage attribute
		const float LocalDamageDone = GetDamage();
		SetDamage(0.f);

		if (LocalDamageDone > 0)
		{
			// Apply the health change and then clamp it
			const float OldHealth = GetHealth();
			SetHealth(FMath::Clamp(OldHealth - LocalDamageDone, 0.0f, GetMaxHealth()));

			if (TargetCharacter)
			{
				// This is proper damage
				TargetCharacter->HandleDamage(LocalDamageDone, HitResult, SourceTags, SourceCharacter, SourceActor);

				// Call for all health changes
				TargetCharacter->HandleHealthChanged(-LocalDamageDone, SourceTags);
			}
		}
	}
	else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		// Handle other health changes such as from healing or direct modifiers
		// First clamp it
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));

		if (TargetCharacter)
		{
			// Call for all health changes
			TargetCharacter->HandleHealthChanged(DeltaValue, SourceTags);
		}
	}
	
	else if (Data.EvaluatedData.Attribute == GetMoveSpeedAttribute())
	{
		if (TargetCharacter)
		{
			// Call for all movespeed changes
			TargetCharacter->HandleMoveSpeedChanged(DeltaValue, SourceTags);
		}
	}
}

