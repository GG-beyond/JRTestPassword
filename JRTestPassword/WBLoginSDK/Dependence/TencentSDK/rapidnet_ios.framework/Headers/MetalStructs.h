#ifndef MetalStructs_h
#define MetalStructs_h
#include <metal_stdlib>
using namespace metal;
struct Float8 {
    float4 data[2];
    void readData(const device float* buffer) {
        data[0].x = buffer[0];
        data[0].y = buffer[1];
        data[0].z = buffer[2];
        data[0].w = buffer[3];
        data[1].x = buffer[4];
        data[1].y = buffer[5];
        data[1].z = buffer[6];
        data[1].w = buffer[7];
    }
    void readData(const device float* buffer, const int step) {
        int offset = 0;
        data[0].x = buffer[offset];   offset+=step;
        data[0].y = buffer[offset];   offset+=step;
        data[0].z = buffer[offset];   offset+=step;
        data[0].w = buffer[offset];   offset+=step;
        data[1].x = buffer[offset];   offset+=step;
        data[1].y = buffer[offset];   offset+=step;
        data[1].z = buffer[offset];   offset+=step;
        data[1].w = buffer[offset];
    }
    float dot(const Float8 b) {
        float sum = 0;
        sum += metal::dot(data[0], b.data[0]);
        sum += metal::dot(data[1], b.data[1]);
        return sum;
    }
};
struct Float16 {
    float4 data[4];
    void readData(const device float* buffer) {
        data[0].x = buffer[0];
        data[0].y = buffer[1];
        data[0].z = buffer[2];
        data[0].w = buffer[3];
        data[1].x = buffer[4];
        data[1].y = buffer[5];
        data[1].z = buffer[6];
        data[1].w = buffer[7];
        data[2].x = buffer[8];
        data[2].y = buffer[9];
        data[2].z = buffer[10];
        data[2].w = buffer[11];
        data[3].x = buffer[12];
        data[3].y = buffer[13];
        data[3].z = buffer[14];
        data[3].w = buffer[15];
    }
    void readData(const device float* buffer, const int step) {
        int offset = 0;
        data[0].x = buffer[offset];  offset+=step;
        data[0].y = buffer[offset];  offset+=step;
        data[0].z = buffer[offset];  offset+=step;
        data[0].w = buffer[offset];  offset+=step;
        data[1].x = buffer[offset];  offset+=step;
        data[1].y = buffer[offset];  offset+=step;
        data[1].z = buffer[offset];  offset+=step;
        data[1].w = buffer[offset];  offset+=step;
        data[2].x = buffer[offset];  offset+=step;
        data[2].y = buffer[offset];  offset+=step;
        data[2].z = buffer[offset];  offset+=step;
        data[2].w = buffer[offset];  offset+=step;
        data[3].x = buffer[offset];  offset+=step;
        data[3].y = buffer[offset];  offset+=step;
        data[3].z = buffer[offset];  offset+=step;
        data[3].w = buffer[offset];
    }
    float dot(const Float16 b) {
        float sum = 0;
        sum += metal::dot(data[0], b.data[0]);
        sum += metal::dot(data[1], b.data[1]);
        sum += metal::dot(data[2], b.data[2]);
        sum += metal::dot(data[3], b.data[3]);
        return sum;
    }
};
struct Float32 {
    float4 data[8];
    void readData(const device float* buffer) {
        data[0].x = buffer[0];
        data[0].y = buffer[1];
        data[0].z = buffer[2];
        data[0].w = buffer[3];
        data[1].x = buffer[4];
        data[1].y = buffer[5];
        data[1].z = buffer[6];
        data[1].w = buffer[7];
        data[2].x = buffer[8];
        data[2].y = buffer[9];
        data[2].z = buffer[10];
        data[2].w = buffer[11];
        data[3].x = buffer[12];
        data[3].y = buffer[13];
        data[3].z = buffer[14];
        data[3].w = buffer[15];
        data[4].x = buffer[16];
        data[4].y = buffer[17];
        data[4].z = buffer[18];
        data[4].w = buffer[19];
        data[5].x = buffer[20];
        data[5].y = buffer[21];
        data[5].z = buffer[22];
        data[5].w = buffer[23];
        data[6].x = buffer[24];
        data[6].y = buffer[25];
        data[6].z = buffer[26];
        data[6].w = buffer[27];
        data[7].x = buffer[28];
        data[7].y = buffer[29];
        data[7].z = buffer[30];
        data[7].w = buffer[31];
    }
    void readData(const device float* buffer, const int step) {
        int offset = 0;
        data[0].x = buffer[offset];  offset+=step;
        data[0].y = buffer[offset];  offset+=step;
        data[0].z = buffer[offset];  offset+=step;
        data[0].w = buffer[offset];  offset+=step;
        data[1].x = buffer[offset];  offset+=step;
        data[1].y = buffer[offset];  offset+=step;
        data[1].z = buffer[offset];  offset+=step;
        data[1].w = buffer[offset];  offset+=step;
        data[2].x = buffer[offset];  offset+=step;
        data[2].y = buffer[offset];  offset+=step;
        data[2].z = buffer[offset];  offset+=step;
        data[2].w = buffer[offset];  offset+=step;
        data[3].x = buffer[offset];  offset+=step;
        data[3].y = buffer[offset];  offset+=step;
        data[3].z = buffer[offset];  offset+=step;
        data[3].w = buffer[offset];  offset+=step;
        data[4].x = buffer[offset];  offset+=step;
        data[4].y = buffer[offset];  offset+=step;
        data[4].z = buffer[offset];  offset+=step;
        data[4].w = buffer[offset];  offset+=step;
        data[5].x = buffer[offset];  offset+=step;
        data[5].y = buffer[offset];  offset+=step;
        data[5].z = buffer[offset];  offset+=step;
        data[5].w = buffer[offset];  offset+=step;
        data[6].x = buffer[offset];  offset+=step;
        data[6].y = buffer[offset];  offset+=step;
        data[6].z = buffer[offset];  offset+=step;
        data[6].w = buffer[offset];  offset+=step;
        data[7].x = buffer[offset];  offset+=step;
        data[7].y = buffer[offset];  offset+=step;
        data[7].z = buffer[offset];  offset+=step;
        data[7].w = buffer[offset];
    }
    float dot(const Float32 b) {
        float sum = 0;
        sum += metal::dot(data[0], b.data[0]);
        sum += metal::dot(data[1], b.data[1]);
        sum += metal::dot(data[2], b.data[2]);
        sum += metal::dot(data[3], b.data[3]);
        sum += metal::dot(data[4], b.data[4]);
        sum += metal::dot(data[5], b.data[5]);
        sum += metal::dot(data[6], b.data[6]);
        sum += metal::dot(data[7], b.data[7]);
        return sum;
    }
};
inline float prelu(float x, float slop) {
    if(x >= 0.0f) {
        return x;
    } else {
        return slop * x;
    }
}
inline float4 prelu_float4(float4 x, float slop) {
    return fmax(0.0f, x) + slop * fmin(0.0f, x);
}
static constant half4 Zero4 = half4(0.0f, 0.0f, 0.0f, 0.0f);
inline half4 prelu4(half4 x, half4 slop) {
    return fmax(Zero4, x) + slop * fmin(Zero4, x);
}
#endif 
