// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sun.generated.h"

UCLASS()
class MUSPROJECT_API ASun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASun();


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UProceduralMeshComponent* ProcMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FVector> SunVertices;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMesh* BaseMesh;

	UPROPERTY(EditAnywhere)
	bool RecreateProceduralMeshButton;


	UFUNCTION(BlueprintCallable)
	void RecreateProceduralMesh();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
