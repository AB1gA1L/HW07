#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "MyPawn.generated.h"
class UCapsuleComponent;
class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext; 
class UInputAction;

struct FInputActionValue;


UCLASS()
class HW07_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	AMyPawn();

protected:
	virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<UCapsuleComponent> CapsuleComp;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<USkeletalMeshComponent> Mesh;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<USpringArmComponent> SpringArm;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<UCameraComponent> Camera;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    TObjectPtr<UInputMappingContext> DefaultMappingContext;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    TObjectPtr<UInputAction> MoveAction;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    TObjectPtr<UInputAction> LookAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
    float MoveSpeed = 500.f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
    float LookSpeed = 100.f;

private:
    void Move(const FInputActionValue& Value);
    void StopMove(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);

    FVector2D CurrentMoveInput;
};
