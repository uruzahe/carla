// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "LidarDescription.generated.h"

USTRUCT()
struct CARLA_API FLidarDescription
{
  GENERATED_BODY()

  /// Number of lasers.
  UPROPERTY(EditAnywhere)
  uint32 Channels = 32u;

  /// Measure distance in centimeters.
  UPROPERTY(EditAnywhere)
  float Range = 1000.0f;

  /// Points generated by all lasers per second.
  UPROPERTY(EditAnywhere)
  uint32 PointsPerSecond = 56000u;

  /// Lidar rotation frequency.
  UPROPERTY(EditAnywhere)
  float RotationFrequency = 10.0f;

  /// Upper laser angle, counts from horizontal, positive values means above
  /// horizontal line.
  UPROPERTY(EditAnywhere)
  float UpperFovLimit = 10.0f;

  /// Lower laser angle, counts from horizontal, negative values means under
  /// horizontal line.
  UPROPERTY(EditAnywhere)
  float LowerFovLimit = -30.0f;

  /// Attenuation Rate in the atmosphere in m^-1
  UPROPERTY(EditAnywhere)
  float AtmospAttenRate = 0.004f;

  /// General drop off rate
  UPROPERTY(EditAnywhere)
  float DropOffGenRate = 0.45f;

  /// General drop off rate
  UPROPERTY(EditAnywhere)
  float DropOffIntensityLimit = 0.8f;

  /// General drop off rate
  UPROPERTY(EditAnywhere)
  float DropOffAtZeroIntensity = 0.4f;



  /// Wether to show debug points of laser hits in simulator.
  UPROPERTY(EditAnywhere)
  bool ShowDebugPoints = false;
};
