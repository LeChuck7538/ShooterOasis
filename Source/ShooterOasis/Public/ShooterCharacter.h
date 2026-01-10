// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class USpringArmComponent;

UCLASS()
class SHOOTEROASIS_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AShooterCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
public:
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom;}
	
protected:
	virtual void BeginPlay() override;

private:
	
	UPROPERTY(VisibleAnywhere, Category = "CameraSet", meta = (AllowPrivateAccess = true))
	TObjectPtr<USpringArmComponent> CameraBoom;
	
};
