// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "RoguelikeGame.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "RPGAttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/** This holds all of the attributes used by abilities, it instantiates a copy of this on every character */
UCLASS()
class ROGUELIKEGAME_API URPGAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:

	// Constructor and overrides
	URPGAttributeSet();
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/** Current Health, when 0 we expect owner to die. Capped by MaxHealth */
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing=OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth_Initial)
	FGameplayAttributeData MaxHealth_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxHealth_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth_Initial_Multiplier)
	FGameplayAttributeData MaxHealth_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxHealth_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth_Flat_Additive)
	FGameplayAttributeData MaxHealth_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxHealth_Flat_Additive)

	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth_Increase_Multiplier)
	FGameplayAttributeData MaxHealth_Increase_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxHealth_Increase_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth_Exponential_Multiplier)
	FGameplayAttributeData MaxHealth_Exponential_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxHealth_Exponential_Multiplier)

	/** MaxHealth is its own attribute, since GameplayEffects may modify it */
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing=OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Damage_Initial)
	FGameplayAttributeData Damage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Damage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Damage_Initial_Multiplier)
	FGameplayAttributeData Damage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Damage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Damage_Increase_Multiplier)
	FGameplayAttributeData Damage_Increase_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Damage_Increase_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Damage_Exponential_Multiplier)
	FGameplayAttributeData Damage_Exponential_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Damage_Exponential_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Attack", ReplicatedUsing = OnRep_AttackDamage_Initial)
	FGameplayAttributeData AttackDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Attack", ReplicatedUsing = OnRep_AttackDamage_Initial_Multiplier)
	FGameplayAttributeData AttackDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Attack", ReplicatedUsing = OnRep_AttackDamage_Increase_Multiplier)
	FGameplayAttributeData AttackDamage_Increase_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackDamage_Increase_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Attack", ReplicatedUsing = OnRep_AttackDamage_Exponential_Multiplier)
	FGameplayAttributeData AttackDamage_Exponential_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackDamage_Exponential_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Spell", ReplicatedUsing = OnRep_SpellDamage_Initial)
	FGameplayAttributeData SpellDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, SpellDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Spell", ReplicatedUsing = OnRep_SpellDamage_Initial_Multiplier)
	FGameplayAttributeData SpellDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, SpellDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Spell", ReplicatedUsing = OnRep_SpellDamage_Increase_Multiplier)
	FGameplayAttributeData SpellDamage_Increase_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, SpellDamage_Increase_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Spell", ReplicatedUsing = OnRep_SpellDamage_Exponential_Multiplier)
	FGameplayAttributeData SpellDamage_Exponential_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, SpellDamage_Exponential_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Physical", ReplicatedUsing = OnRep_PhysicalDamage_Initial)
	FGameplayAttributeData PhysicalDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Physical", ReplicatedUsing = OnRep_PhysicalDamage_Initial_Multiplier)
	FGameplayAttributeData PhysicalDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Physical", ReplicatedUsing = OnRep_PhysicalDamage_Increase_Multiplier)
	FGameplayAttributeData PhysicalDamage_Increase_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalDamage_Increase_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Physical", ReplicatedUsing = OnRep_PhysicalDamage_Exponential_Multiplier)
	FGameplayAttributeData PhysicalDamage_Exponential_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalDamage_Exponential_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental", ReplicatedUsing = OnRep_ElementalDamage_Initial)
	FGameplayAttributeData ElementalDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental", ReplicatedUsing = OnRep_ElementalDamage_Initial_Multiplier)
	FGameplayAttributeData ElementalDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental", ReplicatedUsing = OnRep_ElementalDamage_Increase_Multiplier)
	FGameplayAttributeData ElementalDamage_Increase_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalDamage_Increase_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental", ReplicatedUsing = OnRep_ElementalDamage_Exponential_Multiplier)
	FGameplayAttributeData ElementalDamage_Exponential_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalDamage_Exponential_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Fire", ReplicatedUsing = OnRep_FireDamage_Initial)
	FGameplayAttributeData FireDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Fire", ReplicatedUsing = OnRep_FireDamage_Initial_Multiplier)
	FGameplayAttributeData FireDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Fire", ReplicatedUsing = OnRep_FireDamage_Increase_Multiplier)
	FGameplayAttributeData FireDamage_Increase_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireDamage_Increase_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Fire", ReplicatedUsing = OnRep_FireDamage_Exponential_Multiplier)
	FGameplayAttributeData FireDamage_Exponential_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireDamage_Exponential_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Freeze", ReplicatedUsing = OnRep_FreezeDamage_Initial)
	FGameplayAttributeData FreezeDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Freeze", ReplicatedUsing = OnRep_FreezeDamage_Initial_Multiplier)
	FGameplayAttributeData FreezeDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Freeze", ReplicatedUsing = OnRep_FreezeDamage_Increase_Multiplier)
	FGameplayAttributeData FreezeDamage_Increase_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeDamage_Increase_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Freeze", ReplicatedUsing = OnRep_FreezeDamage_Exponential_Multiplier)
	FGameplayAttributeData FreezeDamage_Exponential_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeDamage_Exponential_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Electric", ReplicatedUsing = OnRep_ElectricDamage_Initial)
	FGameplayAttributeData ElectricDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Electric", ReplicatedUsing = OnRep_ElectricDamage_Initial_Multiplier)
	FGameplayAttributeData ElectricDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Electric", ReplicatedUsing = OnRep_ElectricDamage_Increase_Multiplier)
	FGameplayAttributeData ElectricDamage_Increase_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricDamage_Increase_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Electric", ReplicatedUsing = OnRep_ElectricDamage_Exponential_Multiplier)
	FGameplayAttributeData ElectricDamage_Exponential_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricDamage_Exponential_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Bash", ReplicatedUsing = OnRep_BashDamage_Initial)
		FGameplayAttributeData BashDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, BashDamage_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Bash", ReplicatedUsing = OnRep_BashDamage_Initial_Multiplier)
		FGameplayAttributeData BashDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, BashDamage_Initial_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Bash", ReplicatedUsing = OnRep_BashDamage_Increase_Multiplier)
		FGameplayAttributeData BashDamage_Increase_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, BashDamage_Increase_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Bash", ReplicatedUsing = OnRep_BashDamage_Exponential_Multiplier)
		FGameplayAttributeData BashDamage_Exponential_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, BashDamage_Exponential_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Slash", ReplicatedUsing = OnRep_SlashDamage_Initial)
		FGameplayAttributeData SlashDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, SlashDamage_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Slash", ReplicatedUsing = OnRep_SlashDamage_Initial_Multiplier)
		FGameplayAttributeData SlashDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, SlashDamage_Initial_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Slash", ReplicatedUsing = OnRep_SlashDamage_Increase_Multiplier)
		FGameplayAttributeData SlashDamage_Increase_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, SlashDamage_Increase_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Slash", ReplicatedUsing = OnRep_SlashDamage_Exponential_Multiplier)
		FGameplayAttributeData SlashDamage_Exponential_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, SlashDamage_Exponential_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Stab", ReplicatedUsing = OnRep_StabDamage_Initial)
		FGameplayAttributeData StabDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, StabDamage_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Stab", ReplicatedUsing = OnRep_StabDamage_Initial_Multiplier)
		FGameplayAttributeData StabDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, StabDamage_Initial_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Stab", ReplicatedUsing = OnRep_StabDamage_Increase_Multiplier)
		FGameplayAttributeData StabDamage_Increase_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, StabDamage_Increase_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Stab", ReplicatedUsing = OnRep_StabDamage_Exponential_Multiplier)
		FGameplayAttributeData StabDamage_Exponential_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, StabDamage_Exponential_Multiplier)

	/** AttackPower of the attacker is multiplied by the base Damage to reduce health, so 1.0 means no bonus */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_AttackPower)
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackPower)

	/** Base Damage is divided by DefensePower to get actual damage done, so 1.0 means no bonus */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_DefensePower)
	FGameplayAttributeData DefensePower;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, DefensePower)

	/** MoveSpeed affects how fast characters can move */
	UPROPERTY(BlueprintReadOnly, Category = "MoveSpeed", ReplicatedUsing = OnRep_MoveSpeed)
	FGameplayAttributeData MoveSpeed;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MoveSpeed)

	/** Damage is a 'temporary' attribute used by the DamageExecution to calculate final damage, which then turns into -Health */
	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Damage)

protected:
	/** Helper function to proportionally adjust the value of an attribute when it's associated max attribute changes. (i.e. When MaxHealth increases, Health increases by an amount that maintains the same percentage as before) */
	void AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty);

	// These OnRep functions exist to make sure that the ability system internal representations are synchronized properly during replication
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaxHealth_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaxHealth_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaxHealth_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaxHealth_Increase_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaxHealth_Exponential_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_Damage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_Damage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_Damage_Increase_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_Damage_Exponential_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_AttackDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_AttackDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_AttackDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_AttackDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_SpellDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_SpellDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_SpellDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_SpellDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_PhysicalDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_PhysicalDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_PhysicalDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_PhysicalDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElementalDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElementalDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElementalDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElementalDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FireDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FireDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FireDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FireDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FreezeDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FreezeDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FreezeDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FreezeDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElectricDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElectricDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElectricDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElectricDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_BashDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_BashDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_BashDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_BashDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_SlashDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_SlashDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_SlashDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_SlashDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_StabDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_StabDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_StabDamage_Increase_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_StabDamage_Exponential_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_AttackPower(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_DefensePower(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MoveSpeed(const FGameplayAttributeData& OldValue);

};