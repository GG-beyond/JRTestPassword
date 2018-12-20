#ifndef _RPDNET_20160516_H_
#define _RPDNET_20160516_H_
#include <stdio.h>
#include <memory>
#include <vector>
#include "rpdblob.h"
#include "shared_blob.h"
#include "smart_pointers/shared_ptr.h"
namespace rpdnet {
    class rpd_ctrl;
    class RapidnetInstance;
    typedef RapidnetInstance* HRPDINSTANCE; 
	class rapidnet
	{
	public:
        rapidnet();
        ~rapidnet();
        int init(const char* proto_file_content, const char* model_file_path);
        int init(const char* proto_file_content, const std::string& model_file_path);
        int init(const char* proto_file_content, std::ifstream& model_file_stream);
        int init(const char* proto_file_content, const char* model_data, size_t model_data_length);
        int create_inst(RapidnetInstance* *instance);
        int reshape_inst(RapidnetInstance* instance, const rpd_blob<float>& blob);
        int reshape_inst(RapidnetInstance* instance, int num, int channel, int height, int width);
        int forward(RapidnetInstance* instance, const rpd_blob<float>& in, rpd_blob<float>& output_feature);
        int forward(RapidnetInstance* instance, rpd_blob<float>& in, rpd_blob<float>& output_feature);
        int forward(RapidnetInstance* instance, const rpd_blob<float>& in, const std::vector<int>& output_features_layer_id_list, std::vector<std::vector<smart_pointers::shared_ptr<SharedBlob<float> > > >& output_features);
        int reset_inst(RapidnetInstance* instance);
        int get_feature(RapidnetInstance* instance, size_t layerId, std::vector<rpd_blob<float>*>& featureBlobs);
        int destroy_inst(RapidnetInstance* instance);
        int destory_inst(RapidnetInstance* instance);
        rpd_ctrl *get_rpd_ctrl();
    private:
        rapidnet(const rapidnet& other);
        rapidnet& operator=(const rapidnet & rhs);
        rpd_ctrl* rpd_ctrl_;
	};
}
#endif
