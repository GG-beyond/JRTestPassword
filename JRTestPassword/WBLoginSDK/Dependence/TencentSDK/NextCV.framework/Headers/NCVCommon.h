#ifndef ncvCommon_h
#define ncvCommon_h
#define CV_ENABLE_UNROLLED 1
#ifndef HAVE_CONCURRENCY
    #include <stdint.h>
    #include <float.h>
    #include <limits.h>
#endif
#if HAVE_GCD
	#include <dispatch/dispatch.h>
	#include <pthread.h>
#endif
#define CV_PI   3.1415926535897932384626433832795
#define CV_DECL_ALIGNED(x)
#define CV_MAT_CONT_FLAG_SHIFT  14
#define CV_MAT_CONT_FLAG        (1 << CV_MAT_CONT_FLAG_SHIFT)
#define CV_SUBMAT_FLAG_SHIFT    15
#define CV_SUBMAT_FLAG          (1 << CV_SUBMAT_FLAG_SHIFT)
#define CV_AA 16
#define CV_8U   0
#define CV_8S   1
#define CV_16U  2
#define CV_16S  3
#define CV_32S  4
#define CV_32F  5
#define CV_64F  6
#define CV_FILLED -1
#define  CV_DESCALE(x,n)     (((x) + (1 << ((n)-1))) >> (n))
#define  CV_LKFLOW_PYR_A_READY       1
#define  CV_LKFLOW_PYR_B_READY       2
#define  CV_LKFLOW_INITIAL_GUESSES   4
#define  CV_LKFLOW_GET_MIN_EIGENVALS 8
#define GET_OPTIMIZED(func) (func)
#define __SHRT_MAX__ 32767
#define SHRT_MAX  __SHRT_MAX__
#define SHRT_MIN (-__SHRT_MAX__-1)
#define USHRT_MAX (__SHRT_MAX__ *2  +1)
#define  CV_MALLOC_ALIGN    16
#define CV_8UC1 CV_MAKETYPE(CV_8U,1)
#define CV_8UC2 CV_MAKETYPE(CV_8U,2)
#define CV_8UC3 CV_MAKETYPE(CV_8U,3)
#define CV_8UC4 CV_MAKETYPE(CV_8U,4)
#define CV_16UC1 CV_MAKETYPE(CV_16U,1)
#define CV_16SC1 CV_MAKETYPE(CV_16S,1)
#define CV_16SC2 CV_MAKETYPE(CV_16S,2)
#define CV_32FC1 CV_MAKETYPE(CV_32F,1)
#define CV_32FC2 CV_MAKETYPE(CV_32F,2)
#define CV_32FC3 CV_MAKETYPE(CV_32F,3)
#define CV_32SC1 CV_MAKETYPE(CV_32S,1)
#define CV_32SC2 CV_MAKETYPE(CV_32S,2)
#define CV_64FC1 CV_MAKETYPE(CV_64F,1)
#define CV_64FC2 CV_MAKETYPE(CV_64F,2)
#define CV_CN_MAX     512
#define CV_CN_SHIFT   3
#define CV_DEPTH_MAX  (1 << CV_CN_SHIFT)
#define CV_MAT_DEPTH_MASK       (CV_DEPTH_MAX - 1)
#define CV_MAT_CN_MASK          ((CV_CN_MAX - 1) << CV_CN_SHIFT)
#define CV_MAT_CN(flags)        ((((flags) & CV_MAT_CN_MASK) >> CV_CN_SHIFT) + 1)
#define CV_MAT_DEPTH(flags)     ((flags) & CV_MAT_DEPTH_MASK)
#define CV_MAT_TYPE_MASK        (CV_DEPTH_MAX*CV_CN_MAX - 1)
#define CV_MAT_TYPE(flags)      ((flags) & CV_MAT_TYPE_MASK)
#define CV_ELEM_SIZE(type) \
(CV_MAT_CN(type) << ((((sizeof(size_t)/4+1)*16384|0x3a50) >> CV_MAT_DEPTH(type)*2) & 3))
#define CV_ELEM_SIZE1(type) \
((((sizeof(size_t)<<28)|0x8442211) >> CV_MAT_DEPTH(type)*4) & 15)
#define INT_MAX   __INT_MAX__
#define INT_MIN   (-__INT_MAX__  -1)
#define DBL_MAX __DBL_MAX__
#define CV_ELEM_SIZE(type) \
(CV_MAT_CN(type) << ((((sizeof(size_t)/4+1)*16384|0x3a50) >> CV_MAT_DEPTH(type)*2) & 3))
#define CV_SEQ_ELTYPE_GENERIC        0
#define CV_SEQ_KIND_BITS        2
#define CV_SEQ_ELTYPE_BITS           12
#define CV_SEQ_ELTYPE_MASK           ((1 << CV_SEQ_ELTYPE_BITS) - 1)
#define CV_32S  4
#define CV_MAGIC_MASK       0xFFFF0000
#define CV_SEQ_MAGIC_VAL             0x42990000
#define CV_SEQ_FLAG_SHIFT       (CV_SEQ_KIND_BITS + CV_SEQ_ELTYPE_BITS)
#define CV_SEQ_KIND_CURVE       (1 << CV_SEQ_ELTYPE_BITS)
#define CV_SEQ_FLAG_CLOSED     (1 << CV_SEQ_FLAG_SHIFT)
#define CV_SEQ_FLAG_HOLE       (2 << CV_SEQ_FLAG_SHIFT)
#define CV_32SC2 CV_MAKETYPE(CV_32S,2)
#define CV_SEQ_ELTYPE_POINT          CV_32SC2  
#define CV_SEQ_POLYLINE        (CV_SEQ_KIND_CURVE  | CV_SEQ_ELTYPE_POINT)
#define CV_SEQ_POLYGON         (CV_SEQ_FLAG_CLOSED | CV_SEQ_POLYLINE )
#define CV_NEXT_SEQ_ELEM( elem_size, reader )                 \
{                                                             \
if( ((reader).ptr += (elem_size)) >= (reader).block_max ) \
{                                                         \
cvChangeSeqBlock( &(reader), 1 );                     \
}                                                         \
}
#define CV_READ_SEQ_ELEM( elem, reader )                       \
{                                                              \
memcpy( &(elem), (reader).ptr, sizeof((elem)));            \
CV_NEXT_SEQ_ELEM( sizeof(elem), reader )                   \
}
#define ICV_HLINE( ptr, xl, xr, color, pix_size )            \
{                                                            \
uchar* hline_ptr = (uchar*)(ptr) + (xl)*(pix_size);      \
uchar* hline_max_ptr = (uchar*)(ptr) + (xr)*(pix_size);  \
\
for( ; hline_ptr <= hline_max_ptr; hline_ptr += (pix_size))\
{                                                        \
int hline_j;                                         \
for( hline_j = 0; hline_j < (pix_size); hline_j++ )  \
{                                                    \
hline_ptr[hline_j] = ((uchar*)color)[hline_j];   \
}                                                    \
}                                                        \
}
#if defined __INTEL_COMPILER && !(defined WIN32 || defined _WIN32)   
 #define CV_XADD(addr, delta) _InterlockedExchangeAdd(const_cast<void*>(reinterpret_cast<volatile void*>(addr)), delta)
 #elif defined __GNUC__
#if defined __clang__ && __clang_major__ >= 3 && !defined __ANDROID__
 #ifdef __ATOMIC_SEQ_CST
 #define CV_XADD(addr, delta) __c11_atomic_fetch_add((_Atomic(int)*)(addr), (delta), __ATOMIC_SEQ_CST)
 #else
 #define CV_XADD(addr, delta) __atomic_fetch_add((_Atomic(int)*)(addr), (delta), 5)
 #endif
 #elif __GNUC__ * 10 + __GNUC_MINOR__ >= 42
#if !(defined WIN32 || defined _WIN32) && (defined __i486__ || defined __i586__ || \
        defined __i686__ || defined __MMX__ || defined __SSE__  || defined __ppc__) || \
        (defined __GNUC__ && defined _STLPORT_MAJOR)
 #define CV_XADD __sync_fetch_and_add
 #else
 #include <ext/atomicity.h>
 #define CV_XADD __gnu_cxx::__exchange_and_add
 #endif
#else
 #include <bits/atomicity.h>
 #if __GNUC__ * 10 + __GNUC_MINOR__ >= 34
 #define CV_XADD __gnu_cxx::__exchange_and_add
 #else
 #define CV_XADD __exchange_and_add
 #endif
 #endif
#else
 static inline int CV_XADD(int* addr, int delta)
 { int tmp = *addr; *addr += delta; return tmp; }
#endif
#if defined WIN32 || defined WINCE
#include <windows.h>
#undef small
#undef min
#undef max
#undef abs
#endif
#if defined __linux__ || defined __APPLE__
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#if defined ANDROID
#include <sys/sysconf.h>
#else
#include <sys/sysctl.h>
#endif
#endif
#ifdef _OPENMP
#define HAVE_OPENMP
#endif
#ifdef __APPLE__
#define HAVE_GCD
#endif
#if defined _MSC_VER && _MSC_VER >= 1600
#define HAVE_CONCURRENCY
#endif
#if defined HAVE_TBB
#include "tbb/tbb_stddef.h"
#if TBB_VERSION_MAJOR*100 + TBB_VERSION_MINOR >= 202
#include "tbb/tbb.h"
#include "tbb/task.h"
#if TBB_INTERFACE_VERSION >= 6100
#include "tbb/task_arena.h"
#endif
#undef min
#undef max
#else
#undef HAVE_TBB
#endif 
#endif
#ifndef HAVE_TBB
#if defined HAVE_CSTRIPES
#include "C=.h"
#undef shared
#elif defined HAVE_OPENMP
#include <omp.h>
#elif defined HAVE_GCD
#include <dispatch/dispatch.h>
#include <pthread.h>
#elif defined HAVE_CONCURRENCY
#include <ppl.h>
#endif
#endif
#if defined HAVE_TBB && TBB_VERSION_MAJOR*100 + TBB_VERSION_MINOR >= 202
#  define CV_PARALLEL_FRAMEWORK "tbb"
#elif defined HAVE_CSTRIPES
#  define CV_PARALLEL_FRAMEWORK "cstripes"
#elif defined HAVE_OPENMP
#  define CV_PARALLEL_FRAMEWORK "openmp"
#elif defined HAVE_GCD
#  define CV_PARALLEL_FRAMEWORK "gcd"
#elif defined HAVE_CONCURRENCY
#  define CV_PARALLEL_FRAMEWORK "ms-concurrency"
#endif
#define CV_SEQ_KIND_MASK        (((1 << CV_SEQ_KIND_BITS) - 1)<<CV_SEQ_ELTYPE_BITS)
#define CV_IS_SEQ_CLOSED( seq )     (((seq)->flags & CV_SEQ_FLAG_CLOSED) != 0)
#define CV_SEQ_ELTYPE( seq )   ((seq)->flags & CV_SEQ_ELTYPE_MASK)
#define CV_SEQ_KIND( seq )     ((seq)->flags & CV_SEQ_KIND_MASK )
#define CV_IS_SEQ_CHAIN( seq )   \
(CV_SEQ_KIND(seq) == CV_SEQ_KIND_CURVE && (seq)->elem_size == 1)
#define CV_IS_SEQ_CHAIN_CONTOUR( seq ) \
(CV_IS_SEQ_CHAIN( seq ) && CV_IS_SEQ_CLOSED( seq ))
#define CV_GET_LAST_ELEM( seq, block ) \
((block)->data + ((block)->count - 1)*((seq)->elem_size))
#define CV_IS_SEQ_POINT_SET( seq ) \
((CV_SEQ_ELTYPE(seq) == CV_32SC2 || CV_SEQ_ELTYPE(seq) == CV_32FC2))
#define CV_IS_SEQ_POLYLINE( seq )   \
(CV_SEQ_KIND(seq) == CV_SEQ_KIND_CURVE && CV_IS_SEQ_POINT_SET(seq))
#define CV_MAKETYPE(depth,cn) (CV_MAT_DEPTH(depth) + (((cn)-1) << CV_CN_SHIFT))
#ifndef MIN
#  define MIN(a,b)  ((a) > (b) ? (b) : (a))
#endif
#ifndef MAX
#  define MAX(a,b)  ((a) < (b) ? (b) : (a))
#endif
#define NCV_TREE_NODE_FIELDS(node_type)                               \
int       flags;                   \
int       header_size;             \
struct    node_type* h_prev;       \
struct    node_type* h_next;       \
struct    node_type* v_prev;       \
struct    node_type* v_next  
#define NCV_SEQUENCE_FIELDS()                                              \
NCV_TREE_NODE_FIELDS(NCvSeq);                                           \
int       total;            \
int       elem_size;        \
schar*    block_max;        \
schar*    ptr;              \
int       delta_elems;      \
NCvMemStorage* storage;      \
NCvSeqBlock* free_blocks;    \
NCvSeqBlock* first;        
#define NCV_SEQ_READER_FIELDS()                                      \
int          header_size;                                       \
NCvSeq*       seq;                     \
NCvSeqBlock*  block;                          \
schar*       ptr;          \
schar*       block_min;  \
schar*       block_max;        \
int          delta_index;      \
schar*       prev_elem;  
#define CV_RNG_COEFF 4164903690U
#define CV_DEFAULT(val) = val
typedef unsigned char uchar;
typedef signed char schar;
typedef unsigned short ushort;
typedef int64_t int64;
typedef uint64_t uint64;
typedef uint64 CvRNG;
namespace ncv
{
    typedef struct NCvSeqBlock
    {
        struct NCvSeqBlock*  prev; 
        struct NCvSeqBlock*  next; 
        int    start_index;         
        int    count;             
        schar* data;              
    }
    NCvSeqBlock;
    typedef struct NCvMemBlock
    {
        struct NCvMemBlock*  prev;
        struct NCvMemBlock*  next;
    }
    NCvMemBlock;
    typedef struct NCvMemStorage
    {
        int signature;
        NCvMemBlock* bottom;           
        NCvMemBlock* top;              
        struct  NCvMemStorage* parent; 
        int block_size;               
        int free_space;               
    }
    NCvMemStorage;
    typedef struct NCvSeq
    {
        NCV_SEQUENCE_FIELDS()
    }
    NCvSeq;
    typedef struct NCvSeqReader
    {
        NCV_SEQ_READER_FIELDS()
    }
    NCvSeqReader;
    typedef struct NCvTreeNodeIterator
    {
        const void* node;
        int level;
        int max_level;
    }
    NCvTreeNodeIterator;
    typedef struct NCvTreeNode
    {
        int       flags;         
        int       header_size;   
        struct    NCvTreeNode* h_prev; 
        struct    NCvTreeNode* h_next; 
        struct    NCvTreeNode* v_prev; 
        struct    NCvTreeNode* v_next; 
    }
    NCvTreeNode;
    typedef struct NCvTermCriteria
    {
        int    type;  
        int    max_iter;
        double epsilon;
    }
    NCvTermCriteria;
    struct DecimateAlpha
    {
        int si, di;
        float alpha;
    };
    struct NCvPolyEdge
    {
        NCvPolyEdge() : y0(0), y1(0), x(0), dx(0), next(0) {}
        int y0, y1;
        int x, dx;
        NCvPolyEdge *next;
    };
    enum InterpolationFlags{
        INTER_NEAREST        = 0,
        INTER_LINEAR         = 1,
        INTER_CUBIC          = 2,
        INTER_AREA           = 3,
        INTER_LANCZOS4       = 4,
        INTER_MAX            = 7,
        WARP_FILL_OUTLIERS   = 8,
        WARP_INVERSE_MAP     = 16
    };
    enum InterpolationMasks {
        INTER_BITS      = 5,
        INTER_BITS2     = INTER_BITS * 2,
        INTER_TAB_SIZE  = 1 << INTER_BITS,
        INTER_TAB_SIZE2 = INTER_TAB_SIZE * INTER_TAB_SIZE
    };
    enum { DECOMP_LU=0, DECOMP_SVD=1, DECOMP_EIG=2, DECOMP_CHOLESKY=3, DECOMP_QR=4, DECOMP_NORMAL=16 };
    enum { BLOCK_SIZE = 1024 };
    enum { KERNEL_GENERAL=0, KERNEL_SYMMETRICAL=1, KERNEL_ASYMMETRICAL=2,
        KERNEL_SMOOTH=4, KERNEL_INTEGER=8 };
    static uchar NNDeltaTab_i[INTER_TAB_SIZE2][2];
    const int INTER_REMAP_COEF_BITS=15;
    const int INTER_REMAP_COEF_SCALE=1 << INTER_REMAP_COEF_BITS;
    const int INTER_RESIZE_COEF_BITS=11;
    const int INTER_RESIZE_COEF_SCALE=1 << INTER_RESIZE_COEF_BITS;
    static const int MAX_ESIZE=16;
    static float BilinearTab_f[INTER_TAB_SIZE2][2][2];
    static short BilinearTab_i[INTER_TAB_SIZE2][2][2];
    static float BicubicTab_f[INTER_TAB_SIZE2][4][4];
    static short BicubicTab_i[INTER_TAB_SIZE2][4][4];
    static float Lanczos4Tab_f[INTER_TAB_SIZE2][8][8];
    static short Lanczos4Tab_i[INTER_TAB_SIZE2][8][8];
    enum
    {
        NCV_INTER_NN        =0,
        NCV_INTER_LINEAR    =1,
    };
    enum
    {
        NCV_BGR2GRAY =0,
        NCV_BGRA2GRAY =1,
        NCV_RGB2GRAY =2,
        NCV_RGBA2GRAY =3,
        NCV_RGBA2RGB =4,
        NCV_RGB2BGR =5,
        NCV_RGB2YCrCb =6,
        NCV_RGB2RGBA = 7,
        NCV_RGB2Lab = 8
    };
    enum {
        KIND_SHIFT = 16,
        FIXED_TYPE = 0x8000 << KIND_SHIFT,
        FIXED_SIZE = 0x4000 << KIND_SHIFT,
        KIND_MASK = ~(FIXED_TYPE|FIXED_SIZE) - (1 << KIND_SHIFT) + 1,
        NONE              = 0 << KIND_SHIFT,
        MAT               = 1 << KIND_SHIFT,
        MATX              = 2 << KIND_SHIFT,
        STD_VECTOR        = 3 << KIND_SHIFT,
        STD_VECTOR_VECTOR = 4 << KIND_SHIFT,
        STD_VECTOR_MAT    = 5 << KIND_SHIFT,
        EXPR              = 6 << KIND_SHIFT,
        OPENGL_BUFFER     = 7 << KIND_SHIFT,
        OPENGL_TEXTURE    = 8 << KIND_SHIFT,
        GPU_MAT           = 9 << KIND_SHIFT,
        OCL_MAT           =10 << KIND_SHIFT
    };
    enum { MAGIC_MASK=0xFFFF0000, TYPE_MASK=0x00000FFF, DEPTH_MASK=7 };
    enum { XY_SHIFT = 16, XY_ONE = 1 << XY_SHIFT, DRAWING_STORAGE_BLOCK = (1<<12) - 256 };
    enum { NORM_INF=1, NORM_L1=2, NORM_L2=4, NORM_L2SQR=5, NORM_HAMMING=6, NORM_HAMMING2=7, NORM_TYPE_MASK=7, NORM_RELATIVE=8, NORM_MINMAX=32 };
    enum
    {
        NCV_COMP_CORREL        =0,
    };
    enum BorderTypes {
        BORDER_CONSTANT    = 0, 
        BORDER_REPLICATE   = 1, 
        BORDER_REFLECT     = 2, 
        BORDER_WRAP        = 3, 
        BORDER_REFLECT_101 = 4, 
        BORDER_TRANSPARENT = 5, 
        BORDER_REFLECT101  = BORDER_REFLECT_101, 
        BORDER_DEFAULT     = BORDER_REFLECT_101, 
        BORDER_ISOLATED    = 16 
    };
    enum { GEMM_1_T=1, GEMM_2_T=2, GEMM_3_T=4 };
    static const size_t OUT_OF_RANGE = (size_t)1 << (sizeof(size_t)*8 - 2);
}
#endif 
