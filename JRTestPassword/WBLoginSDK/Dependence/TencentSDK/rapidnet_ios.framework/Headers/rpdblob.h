#ifndef RAPIDNET_INCLUDE_RPDBLOB_H_
#define RAPIDNET_INCLUDE_RPDBLOB_H_
#include <string>
#include <string.h>
#include <cassert>
namespace rpdnet {
    enum eshape_id
    {
        lnum = 0,
        lchannel = 1,
        lheight = 2,
        width = 3
    };
    template <typename T>
    class rpd_blob
    {
    public:
        rpd_blob():data_ (NULL) {
            memset(shape_, 0, shape_dimension_ * sizeof(int));
        }
        ~rpd_blob() {}
    public:
        inline int offset(const int n, const int c = 0, const int h = 0,const int w = 0) const
        {
            return ((n * shape_[1] + c) * shape_[2] + h) * shape_[3] + w;
        }
    public:
        inline std::string& name(){
            return blob_name_;
        }
        inline int num()const{
            return shape_[0];
        }
        inline int channel()const{
            return shape_[1];
        }
        inline int height()const{
            return shape_[2];
        }
        inline int width()const{
            return shape_[3];
        }
        inline T* data(){
            return data_;
        }
        inline const T* data() const {
            return data_;
        }
        inline void set_data(const T* data) {
            data_ = const_cast<T*>(data);
        }
        inline void set_name(const std::string& name){
            blob_name_ = name;
        }
        inline void set_num(int num){
            shape_[0] = num;
        }
        inline void set_channels(int channels){
            shape_[1] = channels;
        }
        inline void set_height(int height){
            shape_[2] = height;
        }
        inline void set_width(int width){
            shape_[3] = width;
        }
        inline int* shape(){
            return shape_;
        }
        inline const int* shape()const{
            return shape_;
        }
        inline int count(int start, int end = shape_dimension_) const
        {
            if (start < 0 || start > shape_dimension_){
                return 0;
            }
            if (end < 0 || end > shape_dimension_){
                return 0;
            }
            int size = 1;
            for (int i = start; i < end; i++)
            {
                size *= shape_[i];
            }
            return size;
        }
        inline int count() const
        {
            return shape_[0] * shape_[1] * shape_[2] * shape_[3];
        }
        inline void set_shape(int* shape)
        {
            memcpy(shape_, shape, shape_dimension_ * sizeof(int));
        }
        const static int shape_dimension_ = 4;
    private:
        int shape_[shape_dimension_];
        T* data_;
        std::string blob_name_;
    };
}
#endif
