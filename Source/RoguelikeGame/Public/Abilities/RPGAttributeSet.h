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

	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth_Additive_Multiplier)
	FGameplayAttributeData MaxHealth_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxHealth_Additive_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth_Multiplicative_Multiplier)
	FGameplayAttributeData MaxHealth_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxHealth_Multiplicative_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Health | HealthRegen", ReplicatedUsing = OnRep_HealthRegen_Flat_Additive)
	FGameplayAttributeData HealthRegen_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, HealthRegen_Flat_Additive)

	UPROPERTY(BlueprintReadOnly, Category = "Health | HealthRegen", ReplicatedUsing = OnRep_HealthRegen_Percent_Multiplier)
	FGameplayAttributeData HealthRegen_Percent_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, HealthRegen_Percent_Multiplier)

	/** MaxHealth is its own attribute, since GameplayEffects may modify it */
	/**UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing=OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxHealth)*/

	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Damage_Initial)
	FGameplayAttributeData Damage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Damage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Damage_Initial_Multiplier)
	FGameplayAttributeData Damage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Damage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Damage_Additive_Multiplier)
	FGameplayAttributeData Damage_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Damage_Additive_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage", ReplicatedUsing = OnRep_Damage_Multiplicative_Multiplier)
	FGameplayAttributeData Damage_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Damage_Multiplicative_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Attack | AttackDamage", ReplicatedUsing = OnRep_AttackDamage_Initial)
	FGameplayAttributeData AttackDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Attack | AttackDamage", ReplicatedUsing = OnRep_AttackDamage_Initial_Multiplier)
	FGameplayAttributeData AttackDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Attack | AttackDamage", ReplicatedUsing = OnRep_AttackDamage_Additive_Multiplier)
	FGameplayAttributeData AttackDamage_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackDamage_Additive_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Attack | AttackDamage", ReplicatedUsing = OnRep_AttackDamage_Multiplicative_Multiplier)
	FGameplayAttributeData AttackDamage_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackDamage_Multiplicative_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Technology | TechnologyDamage", ReplicatedUsing = OnRep_TechnologyDamage_Initial)
	FGameplayAttributeData TechnologyDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, TechnologyDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Technology | TechnologyDamage", ReplicatedUsing = OnRep_TechnologyDamage_Initial_Multiplier)
	FGameplayAttributeData TechnologyDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, TechnologyDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Technology | TechnologyDamage", ReplicatedUsing = OnRep_TechnologyDamage_Additive_Multiplier)
	FGameplayAttributeData TechnologyDamage_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, TechnologyDamage_Additive_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Technology | TechnologyDamage", ReplicatedUsing = OnRep_TechnologyDamage_Multiplicative_Multiplier)
	FGameplayAttributeData TechnologyDamage_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, TechnologyDamage_Multiplicative_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Physical | PhysicalDamage", ReplicatedUsing = OnRep_PhysicalDamage_Initial)
	FGameplayAttributeData PhysicalDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Physical | PhysicalDamage", ReplicatedUsing = OnRep_PhysicalDamage_Initial_Multiplier)
	FGameplayAttributeData PhysicalDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Physical | PhysicalDamage", ReplicatedUsing = OnRep_PhysicalDamage_Additive_Multiplier)
	FGameplayAttributeData PhysicalDamage_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalDamage_Additive_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Physical | PhysicalDamage", ReplicatedUsing = OnRep_PhysicalDamage_Multiplicative_Multiplier)
	FGameplayAttributeData PhysicalDamage_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalDamage_Multiplicative_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | ElementalDamage", ReplicatedUsing = OnRep_ElementalDamage_Initial)
	FGameplayAttributeData ElementalDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | ElementalDamage", ReplicatedUsing = OnRep_ElementalDamage_Initial_Multiplier)
	FGameplayAttributeData ElementalDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | ElementalDamage", ReplicatedUsing = OnRep_ElementalDamage_Additive_Multiplier)
	FGameplayAttributeData ElementalDamage_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalDamage_Additive_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | ElementalDamage", ReplicatedUsing = OnRep_ElementalDamage_Multiplicative_Multiplier)
	FGameplayAttributeData ElementalDamage_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalDamage_Multiplicative_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Fire | FireDamage", ReplicatedUsing = OnRep_FireDamage_Initial)
	FGameplayAttributeData FireDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Fire | FireDamage", ReplicatedUsing = OnRep_FireDamage_Initial_Multiplier)
	FGameplayAttributeData FireDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Fire | FireDamage", ReplicatedUsing = OnRep_FireDamage_Additive_Multiplier)
	FGameplayAttributeData FireDamage_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireDamage_Additive_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Fire | FireDamage", ReplicatedUsing = OnRep_FireDamage_Multiplicative_Multiplier)
	FGameplayAttributeData FireDamage_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireDamage_Multiplicative_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Freeze | FreezeDamage", ReplicatedUsing = OnRep_FreezeDamage_Initial)
	FGameplayAttributeData FreezeDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Freeze | FreezeDamage", ReplicatedUsing = OnRep_FreezeDamage_Initial_Multiplier)
	FGameplayAttributeData FreezeDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Freeze | FreezeDamage", ReplicatedUsing = OnRep_FreezeDamage_Additive_Multiplier)
	FGameplayAttributeData FreezeDamage_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeDamage_Additive_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Freeze | FreezeDamage", ReplicatedUsing = OnRep_FreezeDamage_Multiplicative_Multiplier)
	FGameplayAttributeData FreezeDamage_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeDamage_Multiplicative_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Electric | ElectricDamage", ReplicatedUsing = OnRep_ElectricDamage_Initial)
	FGameplayAttributeData ElectricDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Electric | ElectricDamage", ReplicatedUsing = OnRep_ElectricDamage_Initial_Multiplier)
	FGameplayAttributeData ElectricDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Electric | ElectricDamage", ReplicatedUsing = OnRep_ElectricDamage_Additive_Multiplier)
	FGameplayAttributeData ElectricDamage_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricDamage_Additive_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Elemental | Electric | ElectricDamage", ReplicatedUsing = OnRep_ElectricDamage_Multiplicative_Multiplier)
	FGameplayAttributeData ElectricDamage_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricDamage_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Virus | VirusDamage", ReplicatedUsing = OnRep_VirusDamage_Initial)
		FGameplayAttributeData VirusDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, VirusDamage_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Virus | VirusDamage", ReplicatedUsing = OnRep_VirusDamage_Initial_Multiplier)
		FGameplayAttributeData VirusDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, VirusDamage_Initial_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Virus | VirusDamage", ReplicatedUsing = OnRep_VirusDamage_Additive_Multiplier)
		FGameplayAttributeData VirusDamage_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, VirusDamage_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Virus | VirusDamage", ReplicatedUsing = OnRep_VirusDamage_Multiplicative_Multiplier)
		FGameplayAttributeData VirusDamage_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, VirusDamage_Multiplicative_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Bash | BashDamage", ReplicatedUsing = OnRep_BashDamage_Initial)
	FGameplayAttributeData BashDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, BashDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Bash | BashDamage", ReplicatedUsing = OnRep_BashDamage_Initial_Multiplier)
	FGameplayAttributeData BashDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, BashDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Bash | BashDamage", ReplicatedUsing = OnRep_BashDamage_Additive_Multiplier)
	FGameplayAttributeData BashDamage_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, BashDamage_Additive_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Bash | BashDamage", ReplicatedUsing = OnRep_BashDamage_Multiplicative_Multiplier)
	FGameplayAttributeData BashDamage_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, BashDamage_Multiplicative_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Slash | SlashDamage", ReplicatedUsing = OnRep_SlashDamage_Initial)
	FGameplayAttributeData SlashDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, SlashDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Slash | SlashDamage", ReplicatedUsing = OnRep_SlashDamage_Initial_Multiplier)
	FGameplayAttributeData SlashDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, SlashDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Slash | SlashDamage", ReplicatedUsing = OnRep_SlashDamage_Additive_Multiplier)
	FGameplayAttributeData SlashDamage_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, SlashDamage_Additive_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Slash | SlashDamage", ReplicatedUsing = OnRep_SlashDamage_Multiplicative_Multiplier)
	FGameplayAttributeData SlashDamage_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, SlashDamage_Multiplicative_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Stab | StabDamage", ReplicatedUsing = OnRep_StabDamage_Initial)
	FGameplayAttributeData StabDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, StabDamage_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Stab | StabDamage", ReplicatedUsing = OnRep_StabDamage_Initial_Multiplier)
	FGameplayAttributeData StabDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, StabDamage_Initial_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Stab | StabDamage", ReplicatedUsing = OnRep_StabDamage_Additive_Multiplier)
	FGameplayAttributeData StabDamage_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, StabDamage_Additive_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Damage | Stab | StabDamage", ReplicatedUsing = OnRep_StabDamage_Multiplicative_Multiplier)
	FGameplayAttributeData StabDamage_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, StabDamage_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Area | AreaDamage", ReplicatedUsing = OnRep_AreaDamage_Initial)
		FGameplayAttributeData AreaDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AreaDamage_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Area | AreaDamage", ReplicatedUsing = OnRep_AreaDamage_Initial_Multiplier)
		FGameplayAttributeData AreaDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AreaDamage_Initial_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Area | AreaDamage", ReplicatedUsing = OnRep_AreaDamage_Additive_Multiplier)
		FGameplayAttributeData AreaDamage_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AreaDamage_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Area | AreaDamage", ReplicatedUsing = OnRep_AreaDamage_Multiplicative_Multiplier)
		FGameplayAttributeData AreaDamage_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AreaDamage_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Projectile ! ProjectileDamage", ReplicatedUsing = OnRep_ProjectileDamage_Initial)
		FGameplayAttributeData ProjectileDamage_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ProjectileDamage_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Projectile ! ProjectileDamage", ReplicatedUsing = OnRep_ProjectileDamage_Initial_Multiplier)
		FGameplayAttributeData ProjectileDamage_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ProjectileDamage_Initial_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Projectile ! ProjectileDamage", ReplicatedUsing = OnRep_ProjectileDamage_Additive_Multiplier)
		FGameplayAttributeData ProjectileDamage_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ProjectileDamage_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Damage | Projectile ! ProjectileDamage", ReplicatedUsing = OnRep_ProjectileDamage_Multiplicative_Multiplier)
		FGameplayAttributeData ProjectileDamage_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ProjectileDamage_Multiplicative_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Resist | Physical | PhysicalResist", ReplicatedUsing = OnRep_PhysicalResist_Initial)
	FGameplayAttributeData PhysicalResist_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalResist_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Resist | Physical | PhysicalResist", ReplicatedUsing = OnRep_PhysicalResist_Flat_Additive)
	FGameplayAttributeData PhysicalResist_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalResist_Flat_Additive)

	UPROPERTY(BlueprintReadOnly, Category = "Resist | Physical | PhysicalResist", ReplicatedUsing = OnRep_PhysicalResist_Additive_Multiplier)
	FGameplayAttributeData PhysicalResist_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalResist_Additive_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Resist | Physical | PhysicalResist", ReplicatedUsing = OnRep_PhysicalResist_Multiplicative_Multiplier)
	FGameplayAttributeData PhysicalResist_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalResist_Multiplicative_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | ElementalResist", ReplicatedUsing = OnRep_ElementalResist_Initial)
	FGameplayAttributeData ElementalResist_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalResist_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | ElementalResist", ReplicatedUsing = OnRep_ElementalResist_Flat_Additive)
	FGameplayAttributeData ElementalResist_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalResist_Flat_Additive)

	UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | ElementalResist", ReplicatedUsing = OnRep_ElementalResist_Additive_Multiplier)
	FGameplayAttributeData ElementalResist_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalResist_Additive_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | ElementalResist", ReplicatedUsing = OnRep_ElementalResist_Multiplicative_Multiplier)
	FGameplayAttributeData ElementalResist_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalResist_Multiplicative_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | Fire | FireResist", ReplicatedUsing = OnRep_FireResist_Initial)
	FGameplayAttributeData FireResist_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireResist_Initial)

	UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | Fire | FireResist", ReplicatedUsing = OnRep_FireResist_Flat_Additive)
	FGameplayAttributeData FireResist_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireResist_Flat_Additive)

	UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | Fire | FireResist", ReplicatedUsing = OnRep_FireResist_Additive_Multiplier)
	FGameplayAttributeData FireResist_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireResist_Additive_Multiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | Fire | FireResist", ReplicatedUsing = OnRep_FireResist_Multiplicative_Multiplier)
	FGameplayAttributeData FireResist_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireResist_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | Freeze | FreezeResist", ReplicatedUsing = OnRep_FreezeResist_Initial)
		FGameplayAttributeData FreezeResist_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeResist_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | Freeze | FreezeResist", ReplicatedUsing = OnRep_FreezeResist_Flat_Additive)
		FGameplayAttributeData FreezeResist_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeResist_Flat_Additive)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | Freeze | FreezeResist", ReplicatedUsing = OnRep_FreezeResist_Additive_Multiplier)
		FGameplayAttributeData FreezeResist_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeResist_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | Freeze | FreezeResist", ReplicatedUsing = OnRep_FreezeResist_Multiplicative_Multiplier)
		FGameplayAttributeData FreezeResist_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeResist_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | Electric | ElectricResist", ReplicatedUsing = OnRep_ElectricResist_Initial)
		FGameplayAttributeData ElectricResist_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricResist_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | Electric | ElectricResist", ReplicatedUsing = OnRep_ElectricResist_Flat_Additive)
		FGameplayAttributeData ElectricResist_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricResist_Flat_Additive)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | Electric | ElectricResist", ReplicatedUsing = OnRep_ElectricResist_Additive_Multiplier)
		FGameplayAttributeData ElectricResist_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricResist_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | Elemental | Electric | ElectricResist", ReplicatedUsing = OnRep_ElectricResist_Multiplicative_Multiplier)
		FGameplayAttributeData ElectricResist_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricResist_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | Virus | VirusResist", ReplicatedUsing = OnRep_VirusResist_Initial)
		FGameplayAttributeData VirusResist_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, VirusResist_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | Virus | VirusResist", ReplicatedUsing = OnRep_VirusResist_Flat_Additive)
		FGameplayAttributeData VirusResist_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, VirusResist_Flat_Additive)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | Virus | VirusResist", ReplicatedUsing = OnRep_VirusResist_Additive_Multiplier)
		FGameplayAttributeData VirusResist_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, VirusResist_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | Virus | VirusResist", ReplicatedUsing = OnRep_VirusResist_Multiplicative_Multiplier)
		FGameplayAttributeData VirusResist_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, VirusResist_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | DamageTaken", ReplicatedUsing = OnRep_DamageTaken_Initial)
		FGameplayAttributeData DamageTaken_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, DamageTaken_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | DamageTaken", ReplicatedUsing = OnRep_DamageTaken_Flat_Additive)
		FGameplayAttributeData DamageTaken_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, DamageTaken_Flat_Additive)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | DamageTaken", ReplicatedUsing = OnRep_DamageTaken_Additive_Multiplier)
		FGameplayAttributeData DamageTaken_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, DamageTaken_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | DamageTaken", ReplicatedUsing = OnRep_DamageTaken_Multiplicative_Multiplier)
		FGameplayAttributeData DamageTaken_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, DamageTaken_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Physical | PhysicalDamageTaken", ReplicatedUsing = OnRep_PhysicalDamageTaken_Initial)
		FGameplayAttributeData PhysicalDamageTaken_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalDamageTaken_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Physical | PhysicalDamageTaken", ReplicatedUsing = OnRep_PhysicalDamageTaken_Flat_Additive)
		FGameplayAttributeData PhysicalDamageTaken_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalDamageTaken_Flat_Additive)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Physical | PhysicalDamageTaken", ReplicatedUsing = OnRep_PhysicalDamageTaken_Additive_Multiplier)
		FGameplayAttributeData PhysicalDamageTaken_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalDamageTaken_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Physical | PhysicalDamageTaken", ReplicatedUsing = OnRep_PhysicalDamageTaken_Multiplicative_Multiplier)
		FGameplayAttributeData PhysicalDamageTaken_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalDamageTaken_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | ElementalDamageTaken", ReplicatedUsing = OnRep_ElementalDamageTaken_Initial)
		FGameplayAttributeData ElementalDamageTaken_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalDamageTaken_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | ElementalDamageTaken", ReplicatedUsing = OnRep_ElementalDamageTaken_Flat_Additive)
		FGameplayAttributeData ElementalDamageTaken_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalDamageTaken_Flat_Additive)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | ElementalDamageTaken", ReplicatedUsing = OnRep_ElementalDamageTaken_Additive_Multiplier)
		FGameplayAttributeData ElementalDamageTaken_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalDamageTaken_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | ElementalDamageTaken", ReplicatedUsing = OnRep_ElementalDamageTaken_Multiplicative_Multiplier)
		FGameplayAttributeData ElementalDamageTaken_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElementalDamageTaken_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | Fire | FireDamageTaken", ReplicatedUsing = OnRep_FireDamageTaken_Initial)
		FGameplayAttributeData FireDamageTaken_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireDamageTaken_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | Fire | FireDamageTaken", ReplicatedUsing = OnRep_FireDamageTaken_Flat_Additive)
		FGameplayAttributeData FireDamageTaken_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireDamageTaken_Flat_Additive)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | Fire | FireDamageTaken", ReplicatedUsing = OnRep_FireDamageTaken_Additive_Multiplier)
		FGameplayAttributeData FireDamageTaken_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireDamageTaken_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | Fire | FireDamageTaken", ReplicatedUsing = OnRep_FireDamageTaken_Multiplicative_Multiplier)
		FGameplayAttributeData FireDamageTaken_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireDamageTaken_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | Freeze | FreezeDamageTaken", ReplicatedUsing = OnRep_FreezeDamageTaken_Initial)
		FGameplayAttributeData FreezeDamageTaken_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeDamageTaken_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | Freeze | FreezeDamageTaken", ReplicatedUsing = OnRep_FreezeDamageTaken_Flat_Additive)
		FGameplayAttributeData FreezeDamageTaken_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeDamageTaken_Flat_Additive)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | Freeze | FreezeDamageTaken", ReplicatedUsing = OnRep_FreezeDamageTaken_Additive_Multiplier)
		FGameplayAttributeData FreezeDamageTaken_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeDamageTaken_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | Freeze | FreezeDamageTaken", ReplicatedUsing = OnRep_FreezeDamageTaken_Multiplicative_Multiplier)
		FGameplayAttributeData FreezeDamageTaken_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FreezeDamageTaken_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | Electric | ElectricDamageTaken", ReplicatedUsing = OnRep_ElectricDamageTaken_Initial)
		FGameplayAttributeData ElectricDamageTaken_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricDamageTaken_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | Electric | ElectricDamageTaken", ReplicatedUsing = OnRep_ElectricDamageTaken_Flat_Additive)
		FGameplayAttributeData ElectricDamageTaken_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricDamageTaken_Flat_Additive)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | Electric | ElectricDamageTaken", ReplicatedUsing = OnRep_ElectricDamageTaken_Additive_Multiplier)
		FGameplayAttributeData ElectricDamageTaken_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricDamageTaken_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Elemental | Electric | ElectricDamageTaken", ReplicatedUsing = OnRep_ElectricDamageTaken_Multiplicative_Multiplier)
		FGameplayAttributeData ElectricDamageTaken_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ElectricDamageTaken_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Virus | VirusDamageTaken", ReplicatedUsing = OnRep_VirusDamageTaken_Initial)
		FGameplayAttributeData VirusDamageTaken_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, VirusDamageTaken_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Virus | VirusDamageTaken", ReplicatedUsing = OnRep_VirusDamageTaken_Flat_Additive)
		FGameplayAttributeData VirusDamageTaken_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, VirusDamageTaken_Flat_Additive)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Virus | VirusDamageTaken", ReplicatedUsing = OnRep_VirusDamageTaken_Additive_Multiplier)
		FGameplayAttributeData VirusDamageTaken_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, VirusDamageTaken_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Resist | DamageTaken | Virus | VirusDamageTaken", ReplicatedUsing = OnRep_VirusDamageTaken_Multiplicative_Multiplier)
		FGameplayAttributeData VirusDamageTaken_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, VirusDamageTaken_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Attack | AttackSpeed", ReplicatedUsing = OnRep_AttackSpeed_Initial)
		FGameplayAttributeData AttackSpeed_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackSpeed_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Attack | AttackSpeed", ReplicatedUsing = OnRep_AttackSpeed_Initial_Multiplier)
		FGameplayAttributeData AttackSpeed_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackSpeed_Initial_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Attack | AttackSpeed", ReplicatedUsing = OnRep_AttackSpeed_Additive_Multiplier)
		FGameplayAttributeData AttackSpeed_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackSpeed_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Attack | AttackSpeed", ReplicatedUsing = OnRep_AttackSpeed_Multiplicative_Multiplier)
		FGameplayAttributeData AttackSpeed_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackSpeed_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Technology | TechnologySpeed", ReplicatedUsing = OnRep_TechnologySpeed_Initial)
		FGameplayAttributeData TechnologySpeed_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, TechnologySpeed_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Technology | TechnologySpeed", ReplicatedUsing = OnRep_TechnologySpeed_Initial_Multiplier)
		FGameplayAttributeData TechnologySpeed_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, TechnologySpeed_Initial_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Technology | TechnologySpeed", ReplicatedUsing = OnRep_TechnologySpeed_Additive_Multiplier)
		FGameplayAttributeData TechnologySpeed_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, TechnologySpeed_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Technology | TechnologySpeed", ReplicatedUsing = OnRep_TechnologySpeed_Multiplicative_Multiplier)
		FGameplayAttributeData TechnologySpeed_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, TechnologySpeed_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Area | AreaOfEffect", ReplicatedUsing = OnRep_AreaOfEffect_Initial)
		FGameplayAttributeData AreaOfEffect_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AreaOfEffect_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Area | AreaOfEffect", ReplicatedUsing = OnRep_AreaOfEffect_Initial_Multiplier)
		FGameplayAttributeData AreaOfEffect_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AreaOfEffect_Initial_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Area | AreaOfEffect", ReplicatedUsing = OnRep_AreaOfEffect_Additive_Multiplier)
		FGameplayAttributeData AreaOfEffect_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AreaOfEffect_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Area | AreaOfEffect", ReplicatedUsing = OnRep_AreaOfEffect_Multiplicative_Multiplier)
		FGameplayAttributeData AreaOfEffect_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AreaOfEffect_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Projectile | ProjectileSpeed", ReplicatedUsing = OnRep_ProjectileSpeed_Initial)
		FGameplayAttributeData ProjectileSpeed_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ProjectileSpeed_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Projectile | ProjectileSpeed", ReplicatedUsing = OnRep_ProjectileSpeed_Initial_Multiplier)
		FGameplayAttributeData ProjectileSpeed_Initial_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ProjectileSpeed_Initial_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Projectile | ProjectileSpeed", ReplicatedUsing = OnRep_ProjectileSpeed_Additive_Multiplier)
		FGameplayAttributeData ProjectileSpeed_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ProjectileSpeed_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Projectile | ProjectileSpeed", ReplicatedUsing = OnRep_ProjectileSpeed_Multiplicative_Multiplier)
		FGameplayAttributeData ProjectileSpeed_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ProjectileSpeed_Multiplicative_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Cooldown | CooldownReduction", ReplicatedUsing = OnRep_CooldownReduction_Initial)
		FGameplayAttributeData CooldownReduction_Initial;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, CooldownReduction_Initial)

		UPROPERTY(BlueprintReadOnly, Category = "Cooldown | CooldownReduction", ReplicatedUsing = OnRep_CooldownReduction_Flat_Additive)
		FGameplayAttributeData CooldownReduction_Flat_Additive;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, CooldownReduction_Flat_Additive)

		UPROPERTY(BlueprintReadOnly, Category = "Cooldown | CooldownReduction", ReplicatedUsing = OnRep_CooldownReduction_Additive_Multiplier)
		FGameplayAttributeData CooldownReduction_Additive_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, CooldownReduction_Additive_Multiplier)

		UPROPERTY(BlueprintReadOnly, Category = "Cooldown | CooldownReduction", ReplicatedUsing = OnRep_CooldownReduction_Multiplicative_Multiplier)
		FGameplayAttributeData CooldownReduction_Multiplicative_Multiplier;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, CooldownReduction_Multiplicative_Multiplier)
		


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
	virtual void OnRep_MaxHealth_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaxHealth_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_HealthRegen_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_HealthRegen_Percent_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_Damage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_Damage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_Damage_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_Damage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_AttackDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_AttackDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_AttackDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_AttackDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_TechnologyDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_TechnologyDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_TechnologyDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_TechnologyDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_PhysicalDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_PhysicalDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_PhysicalDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_PhysicalDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElementalDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElementalDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElementalDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElementalDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FireDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FireDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FireDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FireDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FreezeDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FreezeDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FreezeDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FreezeDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElectricDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElectricDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElectricDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElectricDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_VirusDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_VirusDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_VirusDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_VirusDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_BashDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_BashDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_BashDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_BashDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_SlashDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_SlashDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_SlashDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_SlashDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_StabDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_StabDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_StabDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_StabDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_AreaDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_AreaDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_AreaDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_AreaDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ProjectileDamage_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ProjectileDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ProjectileDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ProjectileDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_PhysicalResist_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_PhysicalResist_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_PhysicalResist_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_PhysicalResist_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElementalResist_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElementalResist_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElementalResist_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElementalResist_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FireResist_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FireResist_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FireResist_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FireResist_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FreezeResist_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FreezeResist_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FreezeResist_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FreezeResist_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElectricResist_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElectricResist_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElectricResist_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElectricResist_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_VirusResist_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_VirusResist_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_VirusResist_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_VirusResist_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_DamageTaken_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_DamageTaken_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_DamageTaken_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_DamageTaken_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_PhysicalDamageTaken_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_PhysicalDamageTaken_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_PhysicalDamageTaken_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_PhysicalDamageTaken_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElementalDamageTaken_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElementalDamageTaken_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElementalDamageTaken_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElementalDamageTaken_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FireDamageTaken_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FireDamageTaken_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FireDamageTaken_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FireDamageTaken_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FreezeDamageTaken_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FreezeDamageTaken_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FreezeDamageTaken_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_FreezeDamageTaken_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElectricDamageTaken_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElectricDamageTaken_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElectricDamageTaken_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ElectricDamageTaken_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_VirusDamageTaken_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_VirusDamageTaken_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_VirusDamageTaken_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_VirusDamageTaken_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_AttackSpeed_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_AttackSpeed_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_AttackSpeed_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_AttackSpeed_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_TechnologySpeed_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_TechnologySpeed_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_TechnologySpeed_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_TechnologySpeed_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_AreaOfEffect_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_AreaOfEffect_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_AreaOfEffect_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_AreaOfEffect_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ProjectileSpeed_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ProjectileSpeed_Initial_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ProjectileSpeed_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_ProjectileSpeed_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);
	
	UFUNCTION()
		virtual void OnRep_CooldownReduction_Initial(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_CooldownReduction_Flat_Additive(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_CooldownReduction_Additive_Multiplier(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		virtual void OnRep_CooldownReduction_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue);













	UFUNCTION()
	virtual void OnRep_AttackPower(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_DefensePower(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MoveSpeed(const FGameplayAttributeData& OldValue);

};