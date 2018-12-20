#ifndef DataDef_h
#define DataDef_h
#include <vector>
struct ImgWithLandmarks 
{
    std::vector<int> LandMarkX;				
    std::vector<int> LandMarkY; 				
    std::vector<unsigned char> frame_buffer;			
};
struct DataPack
{
    std::vector<ImgWithLandmarks> VideoData;		
    int frameNum;							
    int LandMarkNum;						
    char *log;							
};
#endif 
