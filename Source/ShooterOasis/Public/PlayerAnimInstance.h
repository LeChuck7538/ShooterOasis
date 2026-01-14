// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

class UCharacterMovementComponent;
class AShooterCharacter;


UCLASS()
class SHOOTEROASIS_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
protected:
	
	virtual void NativeInitializeAnimation() override;
	
	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties(float DeltaTime);
	
private:
	UPROPERTY(Transient, VisibleAnywhere, BlueprintReadOnly, Category = "Player", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AShooterCharacter> ShooterCharacter = nullptr;
	
	UPROPERTY(Transient)
	TObjectPtr<UCharacterMovementComponent> CharacterMovementComp = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player", meta = (AllowPrivateAccess = "true"))
	bool bIsInAir{ false };
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player", meta = (AllowPrivateAccess = "true"))
	bool bIsAccelerating{ false };
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player", meta = (AllowPrivateAccess = "true"))
	float Speed{ 0.0f };
};
