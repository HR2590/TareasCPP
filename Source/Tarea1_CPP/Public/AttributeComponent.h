// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.generated.h"


template <typename T>
class TUAttribute final
{
	FName AttributeName;
	T Value;

public:
	explicit TUAttribute(const FName& InName = TEXT("NONE"), const T& InValue = 0);
	void SetValue(const T& InValue);
	T GetValue() const;
	const FName& GetAttributeName() const;
};





UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TAREA1_CPP_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties

	UAttributeComponent();
	//Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ComponentName;

	//Array Attributes
	TArray<TUAttribute<float>> FloatAttributes;
	TArray<TUAttribute<int32>> Int32Attributes;

	//Cpp Functions
	template <typename T> void SetAttribute(const FName& InName,const T& InValue,TArray<TUAttribute<T>>& OutArray);
	template <typename T> T GetAttribute(const FName& InName,const TArray<TUAttribute<T>>& OutArray);
	template <typename T> void CreateAttribute(const FName& InName,const T& InValue,TArray<TUAttribute<T>>& OutArray);
	template <typename T> bool HasAttribute(const FName& InName,const TArray<TUAttribute<T>>& OutArray);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,FActorComponentTickFunction* ThisTickFunction) override;

	//UFunctions
	UFUNCTION(BlueprintCallable)void CreateAttribute_Float(const FName& InName, const float& InInitialValue);
	UFUNCTION(BlueprintCallable)void SetAttributeValue_Float(const FName& InName,const float& InValue);
	UFUNCTION(BlueprintCallable)float GetAttributeValue_Float(const FName& InName);
	UFUNCTION(BlueprintCallable)int32 GetAttributeValue_Int32(const FName& InName);

	UFUNCTION(BlueprintCallable)bool HasAttribute_Float(const FName& InName);
	
	
};

