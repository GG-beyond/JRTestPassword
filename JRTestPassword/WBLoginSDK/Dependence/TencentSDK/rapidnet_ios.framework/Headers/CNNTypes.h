#ifndef CNNTypes_h
#define CNNTypes_h
#include "CNNMacro.h"
namespace YoutuMetalCNN {
#define kMaxWeightSize (128*128*3*3)
    struct Weights {
        float data[kMaxWeightSize];
    };
    struct ColorConvertPara {
        int type;
        float scale0;
        float scale1;
        float scale2;
        ColorConvertPara() {
            type = 0;
            scale0 = 1.0f;
            scale1 = 1.0f;
            scale2 = 1.0f;
        }
    };
    struct SegmentPreprocessPara{
        int outputWidth;
        int outputHeight;
        int padWidth;
        int padHeight;
        int flipX;
        int flipY;
        SegmentPreprocessPara() {
            outputWidth = 0;
            outputHeight = 0;
            padWidth = 0;
            padHeight = 0;
            flipX = 0;
            flipY = 0;
        }
    };
    inline bool SegmentPreprocessParaEqual(SegmentPreprocessPara para1, SegmentPreprocessPara para2){
        if (para1.outputWidth == para2.outputWidth && para1.outputHeight == para2.outputHeight &&
            para1.padWidth == para2.padWidth && para1.padHeight == para2.padHeight &&
            para1.flipX == para2.flipX && para1.flipY == para2.flipY) {
            return true;
        }
        return false;
    }
    struct CNNDimension {
        int num;
        int channel;
        int height;
        int width;
        int padHeight;
        int padWidth;
        int packedWidth;
        CNNDimension() {
            num = 1;
            channel = 0;
            height = 0;
            width = 0;
            padHeight = 0;
            padWidth = 0;
            packedWidth = 1;
        }
    };
    inline CNNDimension CNNDimensionAdjustPad(CNNDimension dimension, int padWidth, int padHeight) {
        CNNDimension outputDimension = dimension;
        outputDimension.width += 2 * (padWidth - dimension.padWidth);
        outputDimension.height += 2 * (padHeight - dimension.padHeight);
        outputDimension.padWidth = padWidth;
        outputDimension.padHeight = padHeight;
        return outputDimension;
    }
    inline int CNNDimensionGetUnpackWidth(CNNDimension dimension) {
        return dimension.width * dimension.packedWidth;
    }
    inline int CNNDimensionGetSafeUnpackWidth(CNNDimension dimension) {
        return (dimension.width - 2*dimension.padWidth) * dimension.packedWidth;
    }
    inline bool CNNDimensionCanPackWidth4(CNNDimension dimension) {
        if (dimension.packedWidth == 4) {
            return true;
        } else {
            return (dimension.width - 2*dimension.padWidth) % 4 == 0;
        }
    }
    inline CNNDimension CNNDimensionPackWidth4(CNNDimension dimension) {
        if (dimension.packedWidth == 4) {
            return dimension;
        }
        int padWidth = (dimension.padWidth + 3)/4;
        dimension.width = (dimension.width - 2*dimension.padWidth)/4 + 2*padWidth;
        dimension.padWidth = padWidth;
        dimension.packedWidth = 4;
        return dimension;
    }
    inline CNNDimension CNNDimensionUnpackWidth4(CNNDimension dimension) {
        if (dimension.packedWidth == 1) {
            return dimension;
        }
        dimension.width *= dimension.packedWidth;
        dimension.padWidth *= dimension.packedWidth;
        dimension.packedWidth = 1;
        return dimension;
    }
    inline int CNNDimensionSize(CNNDimension dimension) {
        return dimension.num * dimension.channel * dimension.height * dimension.width * dimension.packedWidth;
    }
    inline bool CNNDimensionEuqal(const CNNDimension dim0, const CNNDimension dim1) {
        return dim0.num == dim1.num && dim0.channel == dim1.channel && dim0.height == dim1.height && dim0.width == dim1.width &&
               dim0.packedWidth == dim1.packedWidth && dim0.padWidth == dim1.padWidth && dim0.padHeight == dim1.padHeight;
    }
    struct CNNAddPadingPara{
        int padHeight;
        int padWidth;
        CNNAddPadingPara() {
            padHeight = 0;
            padWidth = 0;
        }
    };
    inline CNNDimension CNNAddPadingGetOutputDimensionGPU(CNNAddPadingPara para, CNNDimension inputDimension) {
        CNNDimension outputDimension;
        outputDimension = inputDimension;
        outputDimension.padHeight = inputDimension.padHeight + para.padHeight;
        outputDimension.padWidth = inputDimension.padWidth + para.padWidth;
        outputDimension.height += 2 * para.padHeight;
        outputDimension.width += 2 * para.padWidth;
        return outputDimension;
    }
    struct CNNBatchNormPara {
    };
    struct CNNConvolutionPara {
        int numGroup;
        int inputChannel;
        int outputChannel;
        int kernelHeight;
        int kernelWidth;
        int strideHeight;
        int strideWidth;
        int padHeight;
        int padWidth;
        int dilationHeight;
        int dilationWidth;
        int outputPadHeight;
        int outputPadWidth;
        CNNConvolutionPara() {
            numGroup = 1;
            inputChannel = 0;
            outputChannel = 0;
            kernelHeight = 0;
            kernelWidth = 0;
            strideHeight = 1;
            strideWidth = 1;
            padHeight = 1;
            padWidth = 1;
            dilationHeight = 1;
            dilationWidth = 1;
            outputPadHeight = 0;
            outputPadWidth = 0;
        }
    };
    inline CNNDimension CNNDeconvolutionGetOutputDimensionGPU(CNNConvolutionPara para, CNNDimension inputDimension) {
        int inputSafeHeight = inputDimension.height - 2 * inputDimension.padHeight;
        int inputSafeUnpackWidth = CNNDimensionGetSafeUnpackWidth(inputDimension);
        CNNDimension outputDimension = inputDimension;
        outputDimension.num = para.numGroup;
        outputDimension.channel = para.outputChannel;
        outputDimension.padHeight = 0;
        outputDimension.padWidth = 0;
        outputDimension.packedWidth = 1;
        outputDimension.height = para.strideHeight * (inputSafeHeight - 1) + para.kernelHeight - 2 * para.padHeight;
        outputDimension.width = para.strideWidth * (inputSafeUnpackWidth - 1) + para.kernelWidth- 2 * para.padWidth;
        return outputDimension;
    }
    inline CNNDimension CNNConvolutionGetOutputDimensionGPU(CNNConvolutionPara para, CNNDimension inputDimension) {
        int inputSafeUnpackWidth = CNNDimensionGetSafeUnpackWidth(inputDimension);
        CNNDimension outputDimension = inputDimension;
        outputDimension.num = para.numGroup;
        outputDimension.channel = para.outputChannel;
        outputDimension.padHeight = 0;
        outputDimension.padWidth = 0;
        outputDimension.packedWidth = 1;
        int kernelExtentH = para.dilationHeight * (para.kernelHeight -1) + 1;
        int kernelExtentW = para.dilationWidth * (para.kernelWidth -1) + 1;
        outputDimension.height = (inputDimension.height + 2 * (para.padHeight - inputDimension.padHeight) - kernelExtentH) / para.strideHeight + 1;
        outputDimension.width = (inputSafeUnpackWidth + 2 * para.padWidth - kernelExtentW) / para.strideWidth + 1;
        return outputDimension;
    }
    inline CNNDimension CNNConvolutionGetOutputDimensionCPU(CNNConvolutionPara para, CNNDimension inputDimension) {
        CNNDimension outputDimension = inputDimension;
        outputDimension.num = para.numGroup;
        outputDimension.channel = para.outputChannel;
        int kernelExtentH = para.dilationHeight * (para.kernelHeight -1) + 1;
        int kernelExtentW = para.dilationWidth * (para.kernelWidth -1) + 1;
        outputDimension.height = (inputDimension.height + 2 * para.padHeight - kernelExtentH) / para.strideHeight + 1;
        outputDimension.width = (inputDimension.width + 2 * para.padWidth - kernelExtentW) / para.strideWidth + 1;
        return outputDimension;
    }
    struct ChannelHeightIndex {
        int channel;
        int height;
        int offset;
    };
}
#endif 
