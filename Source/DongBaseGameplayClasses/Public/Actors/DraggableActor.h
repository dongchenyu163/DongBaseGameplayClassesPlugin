// Fill out your copyright notice in the Description page of Project Settings.
// 

#pragma once

#include "CoreMinimal.h"
#include "Controllers/I_MouseDraggable.h"
#include "GameFramework/Actor.h"
#include "DraggableActor.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogDraggableSystem, Log, All);

UCLASS()
class DONGBASEGAMEPLAYCLASSES_API ADraggableActor : public AActor, public II_MouseDraggable
{
	GENERATED_BODY()


#pragma region 构造函数
	/* ******** */
	// 构造函数
	/* ******** */
public:
	// Sets default values for this actor's properties
	ADraggableActor();

#pragma endregion 构造函数

#pragma region CPP覆盖函数
	/* *********** */
	// CPP覆盖函数
	/* *********** */
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
protected:
	// 蓝图版本的OnGlobalMouseUp函数默认调用以下的CPP版本，所以无需进行实装蓝图版本的该函数。
	virtual void OnGlobalMouseLeftUp_CPP() override;
	void OnGlobalMouseLeftUp_Implementation();
	void OnGlobalTouchUp_Implementation(ETouchIndex::Type InFingerIndex, FVector InLocation);
	virtual void OnGlobalTouchUp_CPP(ETouchIndex::Type InFingerIndex, FVector InLocation) override;
	
private:

#pragma endregion CPP覆盖函数

	
#pragma region CPP函数
	/* ******** */
	// CPP函数
	/* ******** */
public:
protected:
private:
#pragma endregion CPP函数

#pragma region 反射函数
	/* ******** */
	// 反射函数
	/* ******** */
public:
protected:
private:
#pragma endregion 反射函数

#pragma region 蓝图函数
	/* ******** */
	// 蓝图函数
	/* ******** */
public:
	
protected:
	UFUNCTION(BlueprintNativeEvent, Category="Draggable|Actor", meta=(ToolTip="子类必须实现，把需要【被点击】的场景组件添加到【ClickableComponentList】变量中。"))
	void AssignClickedComponentList();

	UFUNCTION(BlueprintNativeEvent, Category="Draggable|Actor", meta=(ToolTip="必须保留父调用"))
	void Handle_BeginCursorOver(UPrimitiveComponent* PrimitiveComponent);
	UFUNCTION(BlueprintNativeEvent, Category="Draggable|Actor", meta=(ToolTip="必须保留父调用"))
	void Handle_EndCursorOver(UPrimitiveComponent* PrimitiveComponent);
	UFUNCTION(BlueprintNativeEvent, Category="Draggable|Actor", meta=(ToolTip="必须保留父调用.由UE4触发，只要点击就会产生。重写点击事件应当覆盖【OnComponentClicked】函数"))
	void Handle_Clicked(UPrimitiveComponent* PrimitiveComponent, FKey Key);
	UFUNCTION(BlueprintNativeEvent, Category="Draggable|Actor", meta=(ToolTip="必须保留父调用"))
	void Handle_Released(UPrimitiveComponent* PrimitiveComponent, FKey Key);
	
	UFUNCTION(BlueprintNativeEvent, Category="Draggable|Actor")
	void Handler_TouchBegin(ETouchIndex::Type Arg, UPrimitiveComponent* PrimitiveComponent);
	UFUNCTION(BlueprintNativeEvent, Category="Draggable|Actor")
	void Handler_TouchEnd(ETouchIndex::Type Arg, UPrimitiveComponent* PrimitiveComponent);
	UFUNCTION(BlueprintNativeEvent, Category="Draggable|Actor")
	void Handler_TouchEnter(ETouchIndex::Type Arg, UPrimitiveComponent* PrimitiveComponent);
	UFUNCTION(BlueprintNativeEvent, Category="Draggable|Actor")
	void Handler_TouchLeave(ETouchIndex::Type Arg, UPrimitiveComponent* PrimitiveComponent);

	// UFUNCTION(BlueprintNativeEvent, Category="Draggable|Actor", meta=(ToolTip="经过ADraggableActor处理后，真正被点击时会被调用。"))
	// virtual void OnComponentClicked(UPrimitiveComponent* PrimitiveComponent, const FKey& Key);

	// UFUNCTION(BlueprintNativeEvent, Category="Draggable|Actor", meta=(ToolTip="经过ADraggableActor处理后，真正被释放的时会被调用。特别是鼠标不在物体上方时释放。"))
	// virtual void OnComponentReleased(UPrimitiveComponent* PrimitiveComponent, const FKey& Key);
private:

#pragma endregion 蓝图函数


#pragma region CPP变量
	/* ******** */
	// CPP变量
	/* ******** */
public:
	
protected:
	// 本Actor是否被点击。
	bool bIsMouseClicking;
	// 本Actor是否被某个手指触碰。
	ETouchIndex::Type ClickingFingerIndex = ETouchIndex::MAX_TOUCHES;

	// 全局，鼠标是否已经点击某个物体了。
	static bool bAnyActorClicked;

	// 全局，共10根手指；每个手指是否已经处于点击的状态。
	static TArray<bool> bFingerTouchedList;
	
private:

#pragma endregion CPP变量

#pragma region 反射变量
	/* ******** */
	// 反射变量
	/* ******** */
	public:
protected:
	UPROPERTY()
	TArray<UPrimitiveComponent*> ClickableComponentList;
	
	UPROPERTY()
	UPrimitiveComponent* MouseClickingComp;
	UPROPERTY()
	TArray<UPrimitiveComponent*> TouchingComponentList;
private:
#pragma endregion 反射变量

#pragma region 蓝图变量
	/* ******** */
	// 蓝图变量
	/* ******** */
	public:
protected:
private:
#pragma endregion 蓝图变量





};
