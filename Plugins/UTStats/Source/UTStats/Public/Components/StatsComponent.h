#pragma once

#include "Components/ActorComponent.h"
#include "StatsComponent.generated.h"

/**
 * @brief Actor component responsible for managing a character stat
 */
UCLASS(ClassGroup=(Custom), DisplayName="Custom Stat Component", meta=(BlueprintSpawnableComponent))
class UTSTATS_API UStatsComponent : public UActorComponent
{
	GENERATED_BODY()
	
	DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FValueZeroEvent, UStatsComponent, OnValueZero);
	DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FValueUpdatedEvent, UStatsComponent, OnValueUpdated, float, Value);

public:
	/**
	 * @brief Create a new instance of the stats component
	 */
	UStatsComponent();
	
	/**
	 * @brief Get the current stat value
	 * @return The current stat value
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Stats")
	float GetValue() const;
	
	/**
	 * @brief Update the current stat value
	 * @param Amount The amount to add to the stat value
	 * @return The new stat value
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Stats")
	float UpdateValue(float Amount);

	/**
	 * @brief Get the maximum value of the stat
	 * @return The maximum value of the stat
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Stats")
	float GetMaxValue() const;
	
	/**
	 * @brief Set the maximum value of the stat
	 * @param NewMaxValue The new maximum value of the stat
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Stats")
	void SetMaxValue(float NewMaxValue);

	/**
	 * @brief Get the amount of value that is regenerated every second
	 * @return The amount of value that is regenerated every second
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Stats")
	float GetRegenerateAmount() const;

	/**
	 * @brief Set the amount of value that is regenerated every second
	 * @param RegenAmount The amount of value that is regenerated every second
	 */
	UFUNCTION(BlueprintCallable, Category = "Unreal Toolbox|Stats")
	void SetRegenerateAmount(float RegenAmount);

	/**
	 * @brief Event that is broadcasted every time the stat value is updated
	 */
	UPROPERTY(BlueprintAssignable, Category = "Unreal Toolbox|Stats|Events")
	FValueUpdatedEvent OnValueUpdated;

	/**
	 * @brief Event that is broadcasted every time the stat value reaches 0
	 */
	UPROPERTY(BlueprintAssignable, Category = "Unreal Toolbox|Stats|Events")
	FValueZeroEvent OnValueZero;

protected:
	/**
	 * @brief The maximum value of the stat 
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats");
	float MaxValue;

	/**
	 * @brief The amount of value that is regenerated every second
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats");
	float Regenerate;
	
	/**
	 * @brief Begins Play for the component
	 */
	virtual void BeginPlay() override;

	/**
	 * @brief Function called every frame on this ActorComponent
	 * @param DeltaTime The time since the last tick
	 * @param TickType The kind of tick this is, for example, are we paused, or 'simulating' in the editor
	 * @param ThisTickFunction Internal tick function struct that caused this to run
	 */
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:	
	/**
	 * @brief The current stat value
	 */
	float Value;
};