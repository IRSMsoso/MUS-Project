// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rock.generated.h"


class UProceduralMeshComponent;


USTRUCT(BlueprintType)
struct FSpectrumRow {
	GENERATED_BODY()

		UPROPERTY(BlueprintReadWrite, VisibleInstanceOnly)
		TArray<float> Spectum;
};

UCLASS()
class MUSPROJECT_API ARock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARock();


	UPROPERTY(BlueprintReadOnly)
	UProceduralMeshComponent* ProcMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FVector> Vertices;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 GridX;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 GridY;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float GridSpacing;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TArray<FSpectrumRow> SpectrumRowBuffer;


	UFUNCTION(BlueprintCallable)
	void RecreateProceduralMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

};
