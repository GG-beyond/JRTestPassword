#ifndef FACEDETECTION_H
#define FACEDETECTION_H
#include <vector>
#include "platform.h"
#if NCNN_OPENCV
#include "opencv.h"
#else
#import <NextCV/Mat.h>
#endif 
#define FACEDETECT_EXPORT __attribute__((visibility("default")))
struct FACEDETECT_EXPORT FaceRect
{
    int x, y, w, h;
    float confidence;
};
struct FACEDETECT_EXPORT FaceDetectionParam
{
    FaceDetectionParam();
    int min_face_size;
    int max_face_size;
    float scale_factor;
    bool big_face_only;
    float cls_threshold;
    float nms_threshold;
    float final_threshold;
    int num_threads;
    int pre_resize_size;
    bool non_square_rect;
    int big_face_only_ext_scales;
};
FACEDETECT_EXPORT int facedetection_init(const char* bundle_path);
FACEDETECT_EXPORT int facedetection_release();
FACEDETECT_EXPORT int facedetection(const ncv::Mat& rgb, std::vector<FaceRect>& faces);
FACEDETECT_EXPORT int facedetection(const ncv::Mat& rgb, std::vector<FaceRect>& faces, const FaceDetectionParam& param);
#endif 
