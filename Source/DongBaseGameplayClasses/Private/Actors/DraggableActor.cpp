// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/DraggableActor.h"

DEFINE_LOG_CATEGORY(LogDraggableSystem);

bool ADraggableActor::bAnyActorClicked = false;
TArray<bool> ADraggableActor::bFingerTouchedList;

// Sets default values
ADraggableActor::ADraggableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADraggableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADraggableActor::OnGlobalMouseLeftUp_CPP()
{
	// OnGlobalMouseLeftUp_CPP();
	II_MouseDraggable::OnGlobalMouseLeftUp_CPP();
	// bAnyActorClicked = false;
	if (UNLIKELY(bIsMouseClicking))
	{
		UE_LOG(LogDraggableSystem, Display, TEXT("Function:[%s] Actor Name: [%s]. Global mouse up!"), ANSI_TO_TCHAR(__FUNCTION__), *GetName());
		bIsMouseClicking = false;
		Handle_Released(MouseClickingComp, EKeys::LeftMouseButton);
	}
}

// void ADraggableActor::OnComponentReleased_Implementation(UPrimitiveComponent* PrimitiveComponent, const FKey& Key)
// {
// }
//
// void ADraggableActor::OnComponentClicked_Implementation(UPrimitiveComponent* PrimitiveComponent, const FKey& Key)
// {
// }

void ADraggableActor::OnGlobalMouseLeftUp_Implementation()
{
	OnGlobalMouseLeftUp_CPP();
}

void ADraggableActor::OnGlobalTouchUp_Implementation(ETouchIndex::Type InFingerIndex, FVector InLocation)
{
	OnGlobalTouchUp_CPP(InFingerIndex, InLocation);
}



void ADraggableActor::Handle_BeginCursorOver_Implementation(UPrimitiveComponent* PrimitiveComponent)
{
	
}

void ADraggableActor::Handle_EndCursorOver_Implementation(UPrimitiveComponent* PrimitiveComponent)
{
}

void ADraggableActor::Handle_Clicked_Implementation(UPrimitiveComponent* PrimitiveComponent, FKey Key)
{
	// if (LIKELY(!bAnyActorClicked))
	{
		// 全局标志位 设为True。
		// bAnyActorClicked = true;
		bIsMouseClicking = true;

		MouseClickingComp = PrimitiveComponent;
		
		UE_LOG(LogDraggableSystem, Display, TEXT("Function:[%s] Actor Name: [%s]. Component clicked!"), ANSI_TO_TCHAR(__FUNCTION__), *GetName());

		// OnComponentClicked(PrimitiveComponent, Key);
	}
}

void ADraggableActor::Handle_Released_Implementation(UPrimitiveComponent* PrimitiveComponent, FKey Key)
{
	bIsMouseClicking = false;

	MouseClickingComp = nullptr;
		
	UE_LOG(LogDraggableSystem, Display, TEXT("Function:[%s] Actor Name: [%s]. Component released!"), ANSI_TO_TCHAR(__FUNCTION__), *GetName());
}

#pragma region Touch Functions
void ADraggableActor::OnGlobalTouchUp_CPP(ETouchIndex::Type InFingerIndex, FVector InLocation)
{
	II_MouseDraggable::OnGlobalTouchUp_CPP(InFingerIndex, InLocation);
	
}

void ADraggableActor::Handler_TouchBegin_Implementation(ETouchIndex::Type Arg, UPrimitiveComponent* PrimitiveComponent)
{
}

void ADraggableActor::Handler_TouchEnd_Implementation(ETouchIndex::Type Arg, UPrimitiveComponent* PrimitiveComponent)
{
}

void ADraggableActor::Handler_TouchEnter_Implementation(ETouchIndex::Type Arg, UPrimitiveComponent* PrimitiveComponent)
{
}

void ADraggableActor::Handler_TouchLeave_Implementation(ETouchIndex::Type Arg, UPrimitiveComponent* PrimitiveComponent)
{
}
#pragma endregion Touch Functions

void ADraggableActor::AssignClickedComponentList_Implementation()
{
	UE_LOG(LogTemp, Error, TEXT("Function:[%s] You MUST override this function!!!"), ANSI_TO_TCHAR(__FUNCTION__));
}

// Called every frame
void ADraggableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADraggableActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	AssignClickedComponentList();
	for (auto CompIt = ClickableComponentList.CreateConstIterator(); CompIt; ++CompIt)
	{
		(*CompIt)->OnBeginCursorOver.AddDynamic(this, &ADraggableActor::Handle_BeginCursorOver);
		(*CompIt)->OnEndCursorOver.AddDynamic(this, &ADraggableActor::Handle_EndCursorOver);
		(*CompIt)->OnClicked.AddDynamic(this, &ADraggableActor::Handle_Clicked);
		(*CompIt)->OnReleased.AddDynamic(this, &ADraggableActor::Handle_Released);
		
		(*CompIt)->OnInputTouchBegin.AddDynamic(this, &ADraggableActor::Handler_TouchBegin);
		(*CompIt)->OnInputTouchEnd.AddDynamic(this, &ADraggableActor::Handler_TouchEnd);
		(*CompIt)->OnInputTouchEnter.AddDynamic(this, &ADraggableActor::Handler_TouchEnter);
		(*CompIt)->OnInputTouchLeave.AddDynamic(this, &ADraggableActor::Handler_TouchLeave);
	}
}

