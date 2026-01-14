// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstance.h"
#include "ShooterCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void UPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	if (APawn* PlayerPawn = TryGetPawnOwner())
	{
		ShooterCharacter = Cast<AShooterCharacter>(PlayerPawn);
		CharacterMovementComp = ShooterCharacter ? ShooterCharacter->GetCharacterMovement() : nullptr;
	}
}


// Animation Parameters that we are going to update on every frame.
void UPlayerAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	// Ensure we try to get the Owning Pawn and the CharacterMovementComponent from the Owning Pawn.
	APawn* OwningPawn = TryGetPawnOwner();
	if (OwningPawn != ShooterCharacter || !IsValid(CharacterMovementComp))
	{
		ShooterCharacter = Cast<AShooterCharacter>(OwningPawn);
		CharacterMovementComp = ShooterCharacter ? ShooterCharacter->GetCharacterMovement() : nullptr;
	}
	
	// Check if we got a successful reference or if not exit function early.
	if (!ShooterCharacter || !CharacterMovementComp) { return; }
	
	// Get the Lateral speed of the character, we do not need vertical velocity so we create Size2D.
	const FVector Velocity = ShooterCharacter->GetVelocity();
	Speed = Velocity.Size2D();
	
	// Is the character in the air?
	bIsInAir = CharacterMovementComp->IsFalling();
	
	// Is the player actively providing movement Input.
	bIsAccelerating = CharacterMovementComp->GetCurrentAcceleration().SizeSquared() > KINDA_SMALL_NUMBER;
}
