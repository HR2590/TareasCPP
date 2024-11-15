// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeComponent.h"



//Constructor
template<typename  T>
TUAttribute<T>::TUAttribute(const FName& InName,const T& InValue):AttributeName(InName),Value(InValue){}


// Sets default values for this component's properties
UAttributeComponent::UAttributeComponent()
{

	PrimaryComponentTick.bCanEverTick = true;
	ComponentName = "DefaultComponent";
}


// Called when the game starts
void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

//UFunctions
void UAttributeComponent::CreateAttribute_Float(const FName& InName, const float& InInitialValue)
{
	CreateAttribute<float>(InName,InInitialValue,FloatAttributes);
}

void UAttributeComponent::SetAttributeValue_Float(const FName& InName,const float& InValue)
{
	SetAttribute<float>(InName,InValue,FloatAttributes);
}
float UAttributeComponent::GetAttributeValue_Float(const FName& InName) 
{
	return GetAttribute<float>(InName,FloatAttributes);
}


bool UAttributeComponent::HasAttribute_Float(const FName& InName)
{
	return HasAttribute<float>(InName,FloatAttributes);
}
int32 UAttributeComponent::GetAttributeValue_Int32(const FName& InName)
{
	return GetAttribute<int32>(InName,Int32Attributes);
	
}


//TUAttribute Functions
template <typename T>
void TUAttribute<T>::SetValue(const T& InValue)
{
	Value=InValue;
}

template <typename T>
T TUAttribute<T>::GetValue() const {return Value;}

template <typename T>
const FName& TUAttribute<T>::GetAttributeName() const
{
	return AttributeName;
}




//Cpp Functions

template <typename T>
void UAttributeComponent::SetAttribute(const FName& InName, const T& InValue, TArray<TUAttribute<T>>& OutArray)
{
	if (!HasAttribute<T>(InName,OutArray)) return;
	
	for (auto& Element : OutArray)
	{
		if (Element.GetAttributeName().IsEqual(InName))
		{
			Element.SetValue(InValue);
			return;
		}
	}

}

template <typename T>
T UAttributeComponent::GetAttribute(const FName& InName,const TArray<TUAttribute<T>>& OutArray)
{
	if (!HasAttribute<T>(InName,OutArray)) return 0;
	for (const auto& Element : OutArray)
	{
		if (Element.GetAttributeName().IsEqual(InName))
		{
			return Element.GetValue();
		}
	}
	return 0;

}

template <typename T>
void UAttributeComponent::CreateAttribute(const FName& InName, const T& InValue, TArray<TUAttribute<T>>& OutArray)
{
		if (HasAttribute<T>(InName,OutArray)) return;
		OutArray.Add(TUAttribute<T>(InName,InValue));
}

template <typename T>
bool UAttributeComponent::HasAttribute(const FName& InName,const TArray<TUAttribute<T>>& OutArray)
{
	for (const auto& Element : OutArray)
	{
		if (Element.GetAttributeName().IsEqual(InName))
		{
			return true;
		}
	}
	return false;
}


