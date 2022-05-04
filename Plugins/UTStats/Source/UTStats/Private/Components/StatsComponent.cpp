#include "Components/StatsComponent.h"
#include "Core/Log.h"

/**
 * @brief Create a new instance of the stats component
 */
UStatsComponent::UStatsComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

/**
 * @brief Begins Play for the component
 */
void UStatsComponent::BeginPlay()
{
	Super::BeginPlay();
	UpdateValue(MaxValue);
	ULog::Info("StatsComponent::BeginPlay", "Stats component initialized");
}

/**
 * @brief Function called every frame on this ActorComponent
 * @param DeltaTime The time since the last tick
 * @param TickType The kind of tick this is, for example, are we paused, or 'simulating' in the editor
 * @param ThisTickFunction Internal tick function struct that caused this to run
 */
void UStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (Regenerate <= 0.0f || Value >= MaxValue)
	{
		return;
	}

	ULog::Info("StatsComponent::TickComponent", "Regenerating value");
	UpdateValue(Regenerate * DeltaTime);
}

/**
 * @brief Get the current stat value
 * @return The current stat value
 */
float UStatsComponent::GetValue() const
{
	return Value;
}

/**
 * @brief Update the current stat value
 * @param Amount The amount to add to the stat value
 * @return The new stat value
 */
float UStatsComponent::UpdateValue(const float Amount)
{
	Value = FMath::Clamp(Value + Amount, 0.0f, MaxValue);
	OnValueUpdated.Broadcast(Value);
	ULog::Info("StatsComponent::UpdateValue", FString("Value updated: ").Append(FString::FromInt(Value)));

	if (Value == 0.0f)
	{
		ULog::Info("StatsComponent::UpdateValue", "Value is zero");
		OnValueZero.Broadcast();
	}
	
	return Value;
}

/**
 * @brief Get the maximum value of the stat
 * @return The maximum value of the stat
 */
float UStatsComponent::GetMaxValue() const
{
	return MaxValue;
}

/**
 * @brief Set the maximum value of the stat
 * @param NewMaxValue The new maximum value of the stat
 */
void UStatsComponent::SetMaxValue(const float NewMaxValue)
{
	MaxValue = NewMaxValue;
	ULog::Info("StatsComponent::SetMaxValue",
		FString("Max value updated: ").Append(FString::FromInt(MaxValue)));
}

/**
 * @brief Get the amount of value that is regenerated every second
 * @return The amount of value that is regenerated every second
 */
float UStatsComponent::GetRegenerateAmount() const
{
	return Regenerate;
}

/**
 * @brief Set the amount of value that is regenerated every second
 * @param RegenAmount The amount of value that is regenerated every second
 */
void UStatsComponent::SetRegenerateAmount(const float RegenAmount)
{
	Regenerate = FMath::Max(RegenAmount, 0.0f);
	ULog::Info("StatsComponent::SetRegenerateAmount",
		FString("Regenerate amount updated: ").Append(FString::FromInt(RegenAmount)));
}