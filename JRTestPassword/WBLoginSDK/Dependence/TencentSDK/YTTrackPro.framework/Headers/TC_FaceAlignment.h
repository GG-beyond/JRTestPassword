#ifndef _TC_FACEALIGNMENT_H_
#define _TC_FACEALIGNMENT_H_
#include <NextCV/Mat.h>
#include <vector>
#include <string>
typedef struct _TC_FaceProfile
{
  std::vector<ncv::Point2f> points;
}TC_FaceProfile;
typedef struct _TC_LeftEye
{
  std::vector<ncv::Point2f> points;
}TC_LeftEye;
typedef struct _TC_LeftEyebrow
{
  std::vector<ncv::Point2f> points;
}TC_LeftEyebrow;
typedef struct _TC_RightEye
{
  std::vector<ncv::Point2f> points;
}TC_RightEye;
typedef struct _TC_RightEyebrow
{
  std::vector<ncv::Point2f> points;
}TC_RightEyebrow;
typedef struct _TC_Nose
{
  std::vector<ncv::Point2f> points;
}TC_Nose;
typedef struct _TC_Mouth
{
  std::vector<ncv::Point2f> points;
}TC_Mouth;
typedef struct _TC_Pupil
{
  std::vector<ncv::Point2f> points;
}TC_Pupil;
typedef struct _TC_FaceShape
{
  TC_FaceProfile faceProfile;
  TC_LeftEyebrow leftEyebrow;
  TC_RightEyebrow rightEyebrow;
  TC_LeftEye leftEye;
  TC_RightEye rightEye;
  TC_Nose nose;
  TC_Mouth mouth;
  TC_Pupil pupil;
}TC_FaceShape;
class UFA;
class PtsPostProc;
class YTFaceRefiner;
class TC_FaceAlignmentRunner
{
public:
    static int iOS_setupEnvironment(const std::string& bundlePath, const unsigned char * udata);
    static void Release();
    static const char* Version();
    TC_FaceAlignmentRunner();
    ~TC_FaceAlignmentRunner();
    void setEnableRefine(bool enable = true);
    int doFaceAlignmentWithCls(const ncv::Mat &rgb, const ncv::Rect& faceRect, TC_FaceShape& faceShape, float &cls);
    int doFaceAlignmentTrackWithCls(const ncv::Mat& rgb,const TC_FaceShape& lastShape, TC_FaceShape& newShape, float &cls);
private:
    TC_FaceAlignmentRunner(TC_FaceAlignmentRunner const &){};
    UFA* m_ufa;
    PtsPostProc *pp;
    YTFaceRefiner *m_refiner;
    bool m_enable_refine;
};
#endif 
