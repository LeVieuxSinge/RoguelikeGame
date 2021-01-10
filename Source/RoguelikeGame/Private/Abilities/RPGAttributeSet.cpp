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
	, MaxHealth_Additive_Multiplier(0.f)
	, MaxHealth_Multiplicative_Multiplier(1.f)
	, MaxHealth(1.f)
	, HealthRegen_Flat_Additive(0.f)
	, HealthRegen_Percent_Multiplier(0.f)
	, Damage_Initial(1.f)
	, Damage_Initial_Multiplier(1.f)
	, Damage_Additive_Multiplier(0.f)
	, Damage_Multiplicative_Multiplier(1.f)
	, AttackDamage_Initial(1.f)
	, AttackDamage_Initial_Multiplier(1.f)
	, AttackDamage_Additive_Multiplier(0.f)
	, AttackDamage_Multiplicative_Multiplier(1.f)
	, TechnologyDamage_Initial(1.f)
	, TechnologyDamage_Initial_Multiplier(1.f)
	, TechnologyDamage_Additive_Multiplier(0.f)
	, TechnologyDamage_Multiplicative_Multiplier(1.f)
	, PhysicalDamage_Initial(1.f)
	, PhysicalDamage_Initial_Multiplier(1.f)
	, PhysicalDamage_Additive_Multiplier(0.f)
	, PhysicalDamage_Multiplicative_Multiplier(1.f)
	, ElementalDamage_Initial(1.f)
	, ElementalDamage_Initial_Multiplier(1.f)
	, ElementalDamage_Additive_Multiplier(0.f)
	, ElementalDamage_Multiplicative_Multiplier(1.f)
	, FireDamage_Initial(1.f)
	, FireDamage_Initial_Multiplier(1.f)
	, FireDamage_Additive_Multiplier(0.f)
	, FireDamage_Multiplicative_Multiplier(1.f)
	, FreezeDamage_Initial(1.f)
	, FreezeDamage_Initial_Multiplier(1.f)
	, FreezeDamage_Additive_Multiplier(0.f)
	, FreezeDamage_Multiplicative_Multiplier(1.f)
	, ElectricDamage_Initial(1.f)
	, ElectricDamage_Initial_Multiplier(1.f)
	, ElectricDamage_Additive_Multiplier(0.f)
	, ElectricDamage_Multiplicative_Multiplier(1.f)
	, VirusDamage_Initial(1.f)
	, VirusDamage_Initial_Multiplier(1.f)
	, VirusDamage_Additive_Multiplier(0.f)
	, VirusDamage_Multiplicative_Multiplier(1.f)
	, BashDamage_Initial(1.f)
	, BashDamage_Initial_Multiplier(1.f)
	, BashDamage_Additive_Multiplier(0.f)
	, BashDamage_Multiplicative_Multiplier(1.f)
	, SlashDamage_Initial(1.f)
	, SlashDamage_Initial_Multiplier(1.f)
	, SlashDamage_Additive_Multiplier(0.f)
	, SlashDamage_Multiplicative_Multiplier(1.f)
	, StabDamage_Initial(1.f)
	, StabDamage_Initial_Multiplier(1.f)
	, StabDamage_Additive_Multiplier(0.f)
	, StabDamage_Multiplicative_Multiplier(1.f)
	, AreaDamage_Initial(1.f)
	, AreaDamage_Initial_Multiplier(1.f)
	, AreaDamage_Additive_Multiplier(0.f)
	, AreaDamage_Multiplicative_Multiplier(1.f)
	, ProjectileDamage_Initial(1.f)
	, ProjectileDamage_Initial_Multiplier(1.f)
	, ProjectileDamage_Additive_Multiplier(0.f)
	, ProjectileDamage_Multiplicative_Multiplier(1.f)
	, PhysicalResist_Initial(1.f)
	, PhysicalResist_Flat_Additive(0.f)
	, PhysicalResist_Additive_Multiplier(0.f)
	, PhysicalResist_Multiplicative_Multiplier(1.f)
	, ElementalResist_Initial(1.f)
	, ElementalResist_Flat_Additive(0.f)
	, ElementalResist_Additive_Multiplier(0.f)
	, ElementalResist_Multiplicative_Multiplier(1.f)
	, FireResist_Initial(1.f)
	, FireResist_Flat_Additive(0.f)
	, FireResist_Additive_Multiplier(0.f)
	, FireResist_Multiplicative_Multiplier(1.f)
	, FreezeResist_Initial(1.f)
	, FreezeResist_Flat_Additive(0.f)
	, FreezeResist_Additive_Multiplier(0.f)
	, FreezeResist_Multiplicative_Multiplier(1.f)
	, ElectricResist_Initial(1.f)
	, ElectricResist_Flat_Additive(0.f)
	, ElectricResist_Additive_Multiplier(0.f)
	, ElectricResist_Multiplicative_Multiplier(1.f)
	, VirusResist_Initial(1.f)
	, VirusResist_Flat_Additive(0.f)
	, VirusResist_Additive_Multiplier(0.f)
	, VirusResist_Multiplicative_Multiplier(1.f)
	, DamageTaken_Initial(1.f)
	, DamageTaken_Flat_Additive(0.f)
	, DamageTaken_Additive_Multiplier(0.f)
	, DamageTaken_Multiplicative_Multiplier(1.f)
	, PhysicalDamageTaken_Initial(1.f)
	, PhysicalDamageTaken_Flat_Additive(0.f)
	, PhysicalDamageTaken_Additive_Multiplier(0.f)
	, PhysicalDamageTaken_Multiplicative_Multiplier(1.f)
	, ElementalDamageTaken_Initial(1.f)
	, ElementalDamageTaken_Flat_Additive(0.f)
	, ElementalDamageTaken_Additive_Multiplier(0.f)
	, ElementalDamageTaken_Multiplicative_Multiplier(1.f)
	, FireDamageTaken_Initial(1.f)
	, FireDamageTaken_Flat_Additive(0.f)
	, FireDamageTaken_Additive_Multiplier(0.f)
	, FireDamageTaken_Multiplicative_Multiplier(1.f)
	, FreezeDamageTaken_Initial(1.f)
	, FreezeDamageTaken_Flat_Additive(0.f)
	, FreezeDamageTaken_Additive_Multiplier(0.f)
	, FreezeDamageTaken_Multiplicative_Multiplier(1.f)
	, ElectricDamageTaken_Initial(1.f)
	, ElectricDamageTaken_Flat_Additive(0.f)
	, ElectricDamageTaken_Additive_Multiplier(0.f)
	, ElectricDamageTaken_Multiplicative_Multiplier(1.f)
	, VirusDamageTaken_Initial(1.f)
	, VirusDamageTaken_Flat_Additive(0.f)
	, VirusDamageTaken_Additive_Multiplier(0.f)
	, VirusDamageTaken_Multiplicative_Multiplier(1.f)
	, AttackSpeed_Initial(1.f)
	, AttackSpeed_Initial_Multiplier(1.f)
	, AttackSpeed_Additive_Multiplier(0.f)
	, AttackSpeed_Multiplicative_Multiplier(1.f)
	, TechnologySpeed_Initial(1.f)
	, TechnologySpeed_Initial_Multiplier(1.f)
	, TechnologySpeed_Additive_Multiplier(0.f)
	, TechnologySpeed_Multiplicative_Multiplier(1.f)
	, AreaOfEffect_Initial(1.f)
	, AreaOfEffect_Initial_Multiplier(1.f)
	, AreaOfEffect_Additive_Multiplier(0.f)
	, AreaOfEffect_Multiplicative_Multiplier(1.f)
	, ProjectileSpeed_Initial(1.f)
	, ProjectileSpeed_Initial_Multiplier(1.f)
	, ProjectileSpeed_Additive_Multiplier(0.f)
	, ProjectileSpeed_Multiplicative_Multiplier(1.f)
	, CooldownReduction_Initial(1.f)
	, CooldownReduction_Flat_Additive(0.f)
	, CooldownReduction_Additive_Multiplier(0.f)
	, CooldownReduction_Multiplicative_Multiplier(1.f)
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
	DOREPLIFETIME(URPGAttributeSet, MaxHealth_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, MaxHealth_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, MaxHealth);
	DOREPLIFETIME(URPGAttributeSet, HealthRegen_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, HealthRegen_Percent_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, Damage_Initial);
	DOREPLIFETIME(URPGAttributeSet, Damage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, Damage_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, Damage_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AttackDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, AttackDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AttackDamage_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AttackDamage_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, TechnologyDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, TechnologyDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, TechnologyDamage_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, TechnologyDamage_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, PhysicalDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, PhysicalDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, PhysicalDamage_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, PhysicalDamage_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElementalDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, ElementalDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElementalDamage_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElementalDamage_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FireDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, FireDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FireDamage_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FireDamage_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FreezeDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, FreezeDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FreezeDamage_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FreezeDamage_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElectricDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, ElectricDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElectricDamage_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElectricDamage_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, VirusDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, VirusDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, VirusDamage_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, VirusDamage_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, BashDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, BashDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, BashDamage_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, BashDamage_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, SlashDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, SlashDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, SlashDamage_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, SlashDamage_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, StabDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, StabDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, StabDamage_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, StabDamage_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AreaDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, AreaDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AreaDamage_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AreaDamage_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ProjectileDamage_Initial);
	DOREPLIFETIME(URPGAttributeSet, ProjectileDamage_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ProjectileDamage_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ProjectileDamage_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, PhysicalResist_Initial);
	DOREPLIFETIME(URPGAttributeSet, PhysicalResist_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, PhysicalResist_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, PhysicalResist_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElementalResist_Initial);
	DOREPLIFETIME(URPGAttributeSet, ElementalResist_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, ElementalResist_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElementalResist_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FireResist_Initial);
	DOREPLIFETIME(URPGAttributeSet, FireResist_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, FireResist_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FireResist_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FreezeResist_Initial);
	DOREPLIFETIME(URPGAttributeSet, FreezeResist_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, FreezeResist_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FreezeResist_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElectricResist_Initial);
	DOREPLIFETIME(URPGAttributeSet, ElectricResist_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, ElectricResist_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElectricResist_Multiplicative_Multiplier)
	DOREPLIFETIME(URPGAttributeSet, VirusResist_Initial);
	DOREPLIFETIME(URPGAttributeSet, VirusResist_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, VirusResist_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, VirusResist_Multiplicative_Multiplier)
	DOREPLIFETIME(URPGAttributeSet, DamageTaken_Initial);
	DOREPLIFETIME(URPGAttributeSet, DamageTaken_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, DamageTaken_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, DamageTaken_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, PhysicalDamageTaken_Initial);
	DOREPLIFETIME(URPGAttributeSet, PhysicalDamageTaken_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, PhysicalDamageTaken_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, PhysicalDamageTaken_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElementalDamageTaken_Initial);
	DOREPLIFETIME(URPGAttributeSet, ElementalDamageTaken_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, ElementalDamageTaken_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElementalDamageTaken_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FireDamageTaken_Initial);
	DOREPLIFETIME(URPGAttributeSet, FireDamageTaken_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, FireDamageTaken_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FireDamageTaken_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FreezeDamageTaken_Initial);
	DOREPLIFETIME(URPGAttributeSet, FreezeDamageTaken_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, FreezeDamageTaken_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, FreezeDamageTaken_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElectricDamageTaken_Initial);
	DOREPLIFETIME(URPGAttributeSet, ElectricDamageTaken_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, ElectricDamageTaken_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ElectricDamageTaken_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, VirusDamageTaken_Initial);
	DOREPLIFETIME(URPGAttributeSet, VirusDamageTaken_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, VirusDamageTaken_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, VirusDamageTaken_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AttackSpeed_Initial);
	DOREPLIFETIME(URPGAttributeSet, AttackSpeed_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AttackSpeed_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AttackSpeed_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, TechnologySpeed_Initial);
	DOREPLIFETIME(URPGAttributeSet, TechnologySpeed_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, TechnologySpeed_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, TechnologySpeed_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AreaOfEffect_Initial);
	DOREPLIFETIME(URPGAttributeSet, AreaOfEffect_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AreaOfEffect_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, AreaOfEffect_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ProjectileSpeed_Initial);
	DOREPLIFETIME(URPGAttributeSet, ProjectileSpeed_Initial_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ProjectileSpeed_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, ProjectileSpeed_Multiplicative_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, CooldownReduction_Initial);
	DOREPLIFETIME(URPGAttributeSet, CooldownReduction_Flat_Additive);
	DOREPLIFETIME(URPGAttributeSet, CooldownReduction_Additive_Multiplier);
	DOREPLIFETIME(URPGAttributeSet, CooldownReduction_Multiplicative_Multiplier);
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

void URPGAttributeSet::OnRep_MaxHealth_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxHealth_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_MaxHealth_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxHealth_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxHealth, OldValue);
}

void URPGAttributeSet::OnRep_HealthRegen_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, HealthRegen_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_HealthRegen_Percent_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, HealthRegen_Percent_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_Damage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Damage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_Damage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Damage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_Damage_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Damage_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_Damage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Damage_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AttackDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AttackDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_AttackDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AttackDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AttackDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AttackDamage_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AttackDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AttackDamage_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_TechnologyDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, TechnologyDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_TechnologyDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, TechnologyDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_TechnologyDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, TechnologyDamage_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_TechnologyDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, TechnologyDamage_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalDamage_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalDamage_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElementalDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_ElementalDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElementalDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalDamage_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElementalDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalDamage_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FireDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_FireDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FireDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireDamage_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FireDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireDamage_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FreezeDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_FreezeDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FreezeDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeDamage_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FreezeDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeDamage_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElectricDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_ElectricDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElectricDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricDamage_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElectricDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricDamage_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_VirusDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, VirusDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_VirusDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, VirusDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_VirusDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, VirusDamage_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_VirusDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, VirusDamage_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_BashDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, BashDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_BashDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, BashDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_BashDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, BashDamage_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_BashDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, BashDamage_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_SlashDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, SlashDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_SlashDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, SlashDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_SlashDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, SlashDamage_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_SlashDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, SlashDamage_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_StabDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, StabDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_StabDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, StabDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_StabDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, StabDamage_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_StabDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, StabDamage_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AreaDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AreaDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_AreaDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AreaDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AreaDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AreaDamage_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AreaDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AreaDamage_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ProjectileDamage_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ProjectileDamage_Initial, OldValue);
}

void URPGAttributeSet::OnRep_ProjectileDamage_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ProjectileDamage_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ProjectileDamage_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ProjectileDamage_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ProjectileDamage_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ProjectileDamage_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalResist_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalResist_Initial, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalResist_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalResist_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalResist_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalResist_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalResist_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalResist_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElementalResist_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalResist_Initial, OldValue);
}

void URPGAttributeSet::OnRep_ElementalResist_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalResist_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_ElementalResist_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalResist_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElementalResist_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalResist_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FireResist_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireResist_Initial, OldValue);
}

void URPGAttributeSet::OnRep_FireResist_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireResist_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_FireResist_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireResist_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FireResist_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireResist_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FreezeResist_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeResist_Initial, OldValue);
}

void URPGAttributeSet::OnRep_FreezeResist_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeResist_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_FreezeResist_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeResist_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FreezeResist_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeResist_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElectricResist_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricResist_Initial, OldValue);
}

void URPGAttributeSet::OnRep_ElectricResist_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricResist_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_ElectricResist_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricResist_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElectricResist_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricResist_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_VirusResist_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, VirusResist_Initial, OldValue);
}

void URPGAttributeSet::OnRep_VirusResist_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, VirusResist_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_VirusResist_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, VirusResist_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_VirusResist_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, VirusResist_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_DamageTaken_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, DamageTaken_Initial, OldValue);
}

void URPGAttributeSet::OnRep_DamageTaken_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, DamageTaken_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_DamageTaken_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, DamageTaken_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_DamageTaken_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, DamageTaken_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalDamageTaken_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalDamageTaken_Initial, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalDamageTaken_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalDamageTaken_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalDamageTaken_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalDamageTaken_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_PhysicalDamageTaken_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, PhysicalDamageTaken_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElementalDamageTaken_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalDamageTaken_Initial, OldValue);
}

void URPGAttributeSet::OnRep_ElementalDamageTaken_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalDamageTaken_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_ElementalDamageTaken_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalDamageTaken_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElementalDamageTaken_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElementalDamageTaken_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FireDamageTaken_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireDamageTaken_Initial, OldValue);
}

void URPGAttributeSet::OnRep_FireDamageTaken_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireDamageTaken_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_FireDamageTaken_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireDamageTaken_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FireDamageTaken_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FireDamageTaken_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FreezeDamageTaken_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeDamageTaken_Initial, OldValue);
}

void URPGAttributeSet::OnRep_FreezeDamageTaken_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeDamageTaken_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_FreezeDamageTaken_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeDamageTaken_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_FreezeDamageTaken_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, FreezeDamageTaken_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElectricDamageTaken_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricDamageTaken_Initial, OldValue);
}

void URPGAttributeSet::OnRep_ElectricDamageTaken_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricDamageTaken_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_ElectricDamageTaken_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricDamageTaken_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ElectricDamageTaken_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ElectricDamageTaken_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_VirusDamageTaken_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, VirusDamageTaken_Initial, OldValue);
}

void URPGAttributeSet::OnRep_VirusDamageTaken_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, VirusDamageTaken_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_VirusDamageTaken_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, VirusDamageTaken_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_VirusDamageTaken_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, VirusDamageTaken_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AttackSpeed_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AttackSpeed_Initial, OldValue);
}

void URPGAttributeSet::OnRep_AttackSpeed_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AttackSpeed_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AttackSpeed_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AttackSpeed_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AttackSpeed_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AttackSpeed_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_TechnologySpeed_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, TechnologySpeed_Initial, OldValue);
}

void URPGAttributeSet::OnRep_TechnologySpeed_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, TechnologySpeed_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_TechnologySpeed_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, TechnologySpeed_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_TechnologySpeed_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, TechnologySpeed_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AreaOfEffect_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AreaOfEffect_Initial, OldValue);
}

void URPGAttributeSet::OnRep_AreaOfEffect_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AreaOfEffect_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AreaOfEffect_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AreaOfEffect_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_AreaOfEffect_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, AreaOfEffect_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ProjectileSpeed_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ProjectileSpeed_Initial, OldValue);
}

void URPGAttributeSet::OnRep_ProjectileSpeed_Initial_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ProjectileSpeed_Initial_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ProjectileSpeed_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ProjectileSpeed_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_ProjectileSpeed_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ProjectileSpeed_Multiplicative_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_CooldownReduction_Initial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, CooldownReduction_Initial, OldValue);
}

void URPGAttributeSet::OnRep_CooldownReduction_Flat_Additive(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, CooldownReduction_Flat_Additive, OldValue);
}

void URPGAttributeSet::OnRep_CooldownReduction_Additive_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, CooldownReduction_Additive_Multiplier, OldValue);
}

void URPGAttributeSet::OnRep_CooldownReduction_Multiplicative_Multiplier(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, CooldownReduction_Multiplicative_Multiplier, OldValue);
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

