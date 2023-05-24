#pragma once

#include <CoreMinimal.h>

#include <Components/StaticMeshComponent.h>
#include <Engine/StaticMesh.h>
#include <GameFramework/Actor.h>
#include <Materials/Material.h>
#include <Materials/MaterialInstanceDynamic.h>
#include <UObject/ObjectMacros.h>
#include <UObject/Object.h>

#include "SpawnableObject.generated.h"

UCLASS()
class ROSINTEGRATION_API ASpawnableObject : public AActor
{
	GENERATED_BODY()

public:
	/// Sets default values for this actor's properties
	ASpawnableObject();

	ASpawnableObject(const FObjectInitializer& ObjectInitializer);

	// A unique id that must be set by the caller
	UPROPERTY(VisibleAnywhere, Category="SpawnableObject")
	int32 Id;

	UMaterialInstanceDynamic* TheMatInst;

	FLinearColor ColorToAssign;

	FString MeshToAssign, MaterialToAssign;

	bool ActivatePhysics = false;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	void SetMaterial();
	void SetStaticMesh();
};
