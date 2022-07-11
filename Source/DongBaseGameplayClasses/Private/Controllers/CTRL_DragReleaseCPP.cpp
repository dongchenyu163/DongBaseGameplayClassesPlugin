// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/CTRL_DragReleaseCPP.h"

#include "Controllers/I_MouseDraggable.h"


// Sets default values
ACTRL_DragReleaseCPP::ACTRL_DragReleaseCPP()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->bShowMouseCursor = true;
	this->bEnableClickEvents = true;
	this->bEnableMouseOverEvents = true;

	this->bEnableTouchEvents = true;
	this->bEnableTouchOverEvents = true;

}

void ACTRL_DragReleaseCPP::Handle_MouseDown()
{
	
}

void ACTRL_DragReleaseCPP::Handle_MouseUp()
{
	const auto& ActorList = GetWorld()->GetCurrentLevel()->Actors;
	for (auto ActorIt = ActorList.CreateConstIterator(); ActorIt; ++ActorIt)
	{
		const II_MouseDraggable* MouseDraggableActorPtr = Cast<II_MouseDraggable>(*ActorIt);
		if (MouseDraggableActorPtr)
		{
			II_MouseDraggable::Execute_OnGlobalMouseLeftUp(*ActorIt);
		}
	}
}

void ACTRL_DragReleaseCPP::Handle_TouchDown(ETouchIndex::Type InFingerIndex, FVector InLocation)
{
	
}

void ACTRL_DragReleaseCPP::Handle_TouchUp(ETouchIndex::Type InFingerIndex, FVector InLocation)
{
	const auto& ActorList = GetWorld()->GetCurrentLevel()->Actors;
	for (auto ActorIt = ActorList.CreateConstIterator(); ActorIt; ++ActorIt)
	{
		const II_MouseDraggable* MouseDraggableActorPtr = Cast<II_MouseDraggable>(*ActorIt);
		if (MouseDraggableActorPtr)
		{
			II_MouseDraggable::Execute_OnGlobalMouseLeftUp(*ActorIt);
		}
	}
}

void ACTRL_DragReleaseCPP::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	// this->InputComponent->BindKey();
	
}

// Called when the game starts or when spawned
void ACTRL_DragReleaseCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACTRL_DragReleaseCPP::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	this->InputComponent->BindKey(EKeys::LeftMouseButton, EInputEvent::IE_Pressed, this, &ACTRL_DragReleaseCPP::Handle_MouseDown);
	this->InputComponent->BindKey(EKeys::LeftMouseButton, EInputEvent::IE_Released, this, &ACTRL_DragReleaseCPP::Handle_MouseUp);
	
	this->InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ACTRL_DragReleaseCPP::Handle_TouchDown);
	this->InputComponent->BindTouch(EInputEvent::IE_Released, this, &ACTRL_DragReleaseCPP::Handle_TouchUp);
}

// Called every frame
void ACTRL_DragReleaseCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

