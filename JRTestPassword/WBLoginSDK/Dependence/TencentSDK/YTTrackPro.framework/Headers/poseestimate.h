#ifndef POSEESTIMATE_H
#define POSEESTIMATE_H
#include "TC_FaceAlignment.h"
const char* pose_sdk_version();
int pose_initModel(std::string modelPath);
int pose_estimate(const TC_FaceShape& faceshape, float& pitch, float& yaw, float& roll);
#endif 
