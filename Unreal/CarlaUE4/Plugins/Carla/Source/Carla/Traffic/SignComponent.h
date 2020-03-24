// Copyright (c) 2020 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Carla/OpenDrive/OpenDrive.h"
#include <utility>
#include "SignComponent.generated.h"

namespace carla
{
namespace road
{
  class Map;
namespace element
{
  class RoadInfoSignal;
}
}
}

/// Class representing an OpenDRIVE Signal
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARLA_API USignComponent : public USceneComponent
{
  GENERATED_BODY()

public:
  USignComponent();

  UFUNCTION(Category = "Traffic Sign", BlueprintPure)
  const FString &GetSignId() const;

  UFUNCTION(Category = "Traffic Sign", BlueprintCallable)
  void SetSignId(const FString &Id);

  // Initialize sign (e.g. generate trigger boxes)
  virtual void InitializeSign(const carla::road::Map &Map);

protected:
  // Called when the game starts
  virtual void BeginPlay() override;

  // Called every frame
  virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

  TArray<std::pair<carla::road::RoadId, const carla::road::element::RoadInfoSignal*>>
      GetAllReferencesToThisSignal(const carla::road::Map &Map);

  /// Generates a trigger box component in the parent actor
  /// BoxSize should be in Unreal units
  UBoxComponent* GenerateTriggerBox(const FTransform &BoxTransform,
      float BoxSize);

private:

  UPROPERTY(Category = "Traffic Sign", EditAnywhere)
  FString SignId;

};
