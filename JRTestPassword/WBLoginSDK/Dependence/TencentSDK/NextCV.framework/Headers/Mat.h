        const _Tp& operator [](int i) const;
        _Tp& operator[](int i);
        _Tp val[cn]; 
    };
    template<typename _Tp, int cn> Vec<_Tp, cn>::Vec()
    {}
    template<typename _Tp, int cn> const _Tp& Vec<_Tp, cn>::operator [](int i) const
    {
        return this->val[i];
    }
    template<typename _Tp, int cn> _Tp& Vec<_Tp, cn>::operator [](int i)
    {
        return this->val[i];
    }
    typedef Vec<uchar, 2> Vec2b;
    typedef Vec<uchar, 3> Vec3b;
    typedef Vec<uchar, 4> Vec4b;
    typedef Vec<short, 2> Vec2s;
    typedef Vec<short, 3> Vec3s;
    typedef Vec<short, 4> Vec4s;
    typedef Vec<ushort, 2> Vec2w;
    typedef Vec<ushort, 3> Vec3w;
    typedef Vec<ushort, 4> Vec4w;
    typedef Vec<int, 2> Vec2i;
    typedef Vec<int, 3> Vec3i;
    typedef Vec<int, 4> Vec4i;
    typedef Vec<int, 6> Vec6i;
    typedef Vec<int, 8> Vec8i;
    typedef Vec<float, 2> Vec2f;
    typedef Vec<float, 3> Vec3f;
    typedef Vec<float, 4> Vec4f;
    typedef Vec<float, 6> Vec6f;
    typedef Vec<double, 2> Vec2d;
    typedef Vec<double, 3> Vec3d;
    typedef Vec<double, 4> Vec4d;
    typedef Vec<double, 6> Vec6d;
    template<typename _Tp> class Scalar_ : public Vec<_Tp, 4>
    {
    public:
        Scalar_();
        Scalar_(_Tp v0, _Tp v1, _Tp v2=0, _Tp v3=0);
        Scalar_(_Tp v0);
        static Scalar_<_Tp> all(_Tp v0);
        bool isReal() const;
    };
    typedef Scalar_<double> Scalar;
    template<typename _Tp> inline Scalar_<_Tp>::Scalar_()
    { this->val[0] = this->val[1] = this->val[2] = this->val[3] = 0; }
    template<typename _Tp> inline Scalar_<_Tp>::Scalar_(_Tp v0, _Tp v1, _Tp v2, _Tp v3)
    { this->val[0] = v0; this->val[1] = v1; this->val[2] = v2; this->val[3] = v3; }
    template<typename _Tp> inline Scalar_<_Tp>::Scalar_(_Tp v0)
    { this->val[0] = v0; this->val[1] = this->val[2] = this->val[3] = 0; }
    template<typename _Tp> inline Scalar_<_Tp> Scalar_<_Tp>::all(_Tp v0)
    { return Scalar_<_Tp>(v0, v0, v0, v0); }
    template<typename _Tp> inline bool Scalar_<_Tp>::isReal() const
    {
        return this->val[1] == 0 && this->val[2] == 0 && this->val[3] == 0;
    }
    class MatAllocator
    {
    public:
        MatAllocator() {}
        virtual ~MatAllocator() {}
        virtual void allocate(int dims, const int* sizes, int type, int*& refcount,
                              uchar*& datastart, uchar*& data, size_t* step) = 0;
        virtual void deallocate(int* refcount, uchar* datastart, uchar* data) = 0;
    };
    class MatExpr;
    class Mat
    {
    public:
        Mat();
        Mat(int rows, int cols, int type);
		Mat(int _rows, int _cols, int _type, const Scalar& _s);
        Mat(Size size, int type);
		Mat(Size _sz, int _type, const Scalar& _s);
        Mat(const Mat& m);
        Mat(const Mat& m, const Rect& roi);
        Mat(int rows, int cols, int type, void* data, size_t step=AUTO_STEP);
        Mat(const Mat& m, const Range& rowRange, const Range& colRange=Range::all());
        Mat(const Mat& m, const Range* ranges);
        ~Mat();
        Mat& operator = (const Mat& m);
        Mat& operator = (const Scalar& s);
        Mat& operator = (const MatExpr& e);
        Mat& setTo(float _value);
        Mat& setTo(Scalar _value);
        MatExpr t() const;
        MatExpr inv(int method=DECOMP_LU) const;
        Mat mul(const Mat & m, double scale=1) const;
        Mat row(int y) const;
        Mat col(int x) const;
        Mat rowRange(int startrow, int endrow) const;
        Mat rowRange(const Range& r) const;
        Mat colRange(int startcol, int endcol) const;
        Mat colRange(const Range& r) const;
        Mat clone() const;
        void copyTo( Mat &m ) const;
        void convertTo( Mat & dst, int _type, float alpha=1, float beta=0 ) const;
        void create(int rows, int cols, int type);
        void create(Size size, int type);
        void create(int d, const int* _sizes, int _type);
        void addref();
        void release();
        void deallocate();
        void locateROI( Size& wholeSize, Point2i& ofs ) const;
        Mat& adjustROI( int dtop, int dbottom, int dleft, int dright );
        Mat operator()( const Rect& roi ) const;
        Mat operator()( const Range* ranges ) const;
        bool isContinuous() const;
        bool isSubmatrix() const;
        static MatExpr eye(int rows, int cols, int type);
        static MatExpr eye(Size size, int type);
        size_t elemSize() const;
        size_t elemSize1() const;
        int type() const;
        int depth() const;
        int channels() const;
        bool empty() const;
        size_t total() const;
        size_t step1(int i=0) const;
        template<typename _Tp> _Tp& at(int i0=0);
        template<typename _Tp> const _Tp& at(int i0=0) const;
        template<typename _Tp> _Tp& at(int i0, int i1);
        template<typename _Tp> const _Tp& at(int i0, int i1) const;
        uchar* ptr(int i0=0);
        const uchar* ptr(int i0=0) const;
        template<typename _Tp> _Tp* ptr(int y=0);
        template<typename _Tp> const _Tp* ptr(int y=0) const;
        enum { MAGIC_VAL=0x42FF0000, AUTO_STEP=0, CONTINUOUS_FLAG=CV_MAT_CONT_FLAG, SUBMATRIX_FLAG=CV_SUBMAT_FLAG };
        int flags;
        int dims;
        int rows, cols;
        uchar* data;
        int* refcount;
        uchar* datastart;
        uchar* dataend;
        uchar* datalimit;
        MatAllocator* allocator;
        struct MSize
        {
            MSize(int* _p);
            Size operator()() const;
            const int& operator[](int i) const;
            int& operator[](int i);
            operator const int*() const;
            bool operator == (const MSize& sz) const;
            bool operator != (const MSize& sz) const;
            int* p;
        };
        struct MStep
        {
            MStep();
            MStep(size_t s);
            const size_t& operator[](int i) const;
            size_t& operator[](int i);
            operator size_t() const;
            MStep& operator = (size_t s);
            size_t* p;
            size_t buf[2];
        protected:
            MStep& operator = (const MStep&);
        };
        MSize size;
        MStep step;
    protected:
        void initEmpty();
        void copySize(const Mat& m);
        bool fixedType() const;
        Size getContinuousSize( const Mat& m1, const Mat& m2, int widthScale=1 ) const;
    };
    class MatExpr;
    class MatOp
    {
    public:
        MatOp() {};
        virtual ~MatOp() {};
        virtual void assign(const MatExpr& expr, Mat& m, int type=-1) const = 0;
    };
    class MatExpr
    {
    public:
        MatExpr() : op(0), flags(0), a(Mat()), b(Mat()), c(Mat()), alpha(0), beta(0), s(Scalar()) {}
        MatExpr(const MatOp* _op, int _flags, const Mat& _a=Mat(), const Mat& _b=Mat(),
                const Mat& _c=Mat(), double _alpha=1, double _beta=1, const Scalar& _s=Scalar())
        : op(_op), flags(_flags), a(_a), b(_b), c(_c), alpha(_alpha), beta(_beta), s(_s){}
        explicit MatExpr(const Mat& m);
        operator Mat() const
        {
            Mat m;
            op->assign(*this, m);
            return m;
        }
        MatExpr row(int y) const;
        MatExpr col(int x) const;
        MatExpr diag(int d=0) const;
        MatExpr operator()( const Range& rowRange, const Range& colRange ) const;
        MatExpr operator()( const Rect& roi ) const;
        Mat cross(const Mat& m) const;
        double dot(const Mat& m) const;
        MatExpr t() const;
        MatExpr inv(int method = DECOMP_LU) const;
        MatExpr mul(const MatExpr& e, double scale=1) const;
        MatExpr mul(const Mat& m, double scale=1) const;
        Size size() const;
        int type() const;
        const MatOp* op;
        int flags;
        Mat a, b, c;
        double alpha, beta;
        Scalar s;
    };
    template<typename _Tp> inline _Tp& Mat::at(int i0)
    {
        if( isContinuous() || size.p[0] == 1 )
            return ((_Tp*)data)[i0];
        if( size.p[1] == 1 )
            return *(_Tp*)(data + step.p[0]*i0);
        int i = i0/cols, j = i0 - i*cols;
        return ((_Tp*)(data + step.p[0]*i))[j];
    }
    template<typename _Tp> inline const _Tp& Mat::at(int i0) const
    {
        if( isContinuous() || size.p[0] == 1 )
            return ((const _Tp*)data)[i0];
        if( size.p[1] == 1 )
            return *(const _Tp*)(data + step.p[0]*i0);
        int i = i0/cols, j = i0 - i*cols;
        return ((const _Tp*)(data + step.p[0]*i))[j];
    }
    template<typename _Tp> inline _Tp& Mat::at(int i0, int i1)
    {
        return ((_Tp*)(data + step.p[0]*i0))[i1];
    }
    template<typename _Tp> inline const _Tp& Mat::at(int i0, int i1) const
    {
        return ((const _Tp*)(data + step.p[0]*i0))[i1];
    }
    template<typename _Tp> inline _Tp* Mat::ptr(int y)
    {
        return (_Tp*)(data + step.p[0] * y);
    }
    template<typename _Tp> inline const _Tp* Mat::ptr(int y) const
    {
        return (const _Tp*)(data + step.p[0] * y);
    }
    class NAryMatIterator
    {
    public:
        NAryMatIterator();
        NAryMatIterator(const Mat** arrays, uchar** ptrs, int narrays=-1);
        NAryMatIterator(const Mat** arrays, Mat* planes, int narrays=-1);
        void init(const Mat** arrays, Mat* planes, uchar** ptrs, int narrays=-1);
        NAryMatIterator& operator ++();
        NAryMatIterator operator ++(int);
        const Mat** arrays;
        Mat* planes;
        uchar** ptrs;
        int narrays;
        size_t nplanes;
        size_t size;
    protected:
        int iterdepth;
        size_t idx;
    };
    class SVD
    {
    public:
        enum { MODIFY_A=1, NO_UV=2, FULL_UV=4 };
        SVD();
        SVD( const Mat & src, int flags=0 );
        SVD& operator ()( const Mat & src, int flags=0 );
        static void compute( const Mat & src, Mat & w,
                            Mat & u, Mat & vt, int flags=0 );
        static void backSubst( const Mat & w, const Mat & u,
                              const Mat & vt, const Mat & rhs,
                              Mat & dst );
        Mat u, w, vt;
    };
    void preprocess2DKernel( Mat& kernel, std::vector<Point2i>& coords, std::vector<uchar>& coeffs );
    double invert( const Mat & src, Mat & dst, int method=DECOMP_LU );
    void integral(const Mat & src, Mat & sum);
    void cvtColor(const Mat & src, Mat & dst, const int & type);
    void resize(const Mat & src, Mat & dst, Size dsize, double fx_1=0, double fy_1=0, int interpolation=NCV_INTER_LINEAR);
    template<typename _Tp, class _EqPredicate> int partition( const std::vector<_Tp>& _vec, std::vector<int>& labels, _EqPredicate predicate=_EqPredicate());
    void groupRectangles(std::vector<Rect>& rectList, std::vector<int>& weights, int groupThreshold, double eps = 0.2);
    void groupRectangles(std::vector<Rect>& rectList, int groupThreshold, double eps, std::vector<int>* weights, std::vector<double>* levelWeights );
    void mixChannels( const Mat* src, size_t nsrcs, Mat* dst, size_t ndsts, const int* fromTo, size_t npairs );
    NCvSeq* cvMakeSeqHeaderForArray( int seq_flags, int header_size, int elem_size,
                                     const void *array, int total, NCvSeq *seq, NCvSeqBlock * block );
    void scalarToRawData(const Scalar& s, void* _buf, int type, int unroll_to);
    void Line( Mat& img, Point2i pt1, Point2i pt2, const void* _color, int connectivity = 8 );
    float mean( const Mat & _src, const Mat & _mask );
    double mean_32FC1( const Mat & src, const Mat & mask );
    void meanStdDev( const Mat & src, Mat & mean, Mat & sdv, const Mat & mask );
    void minMaxIdx(const Mat & src, double* minVal, double* maxVal, const Mat & mask);
    void minMaxLoc( const Mat & img, double* minVal, double* maxVal, const Mat & mask );
    void normalize( const Mat & src, Mat & dst, double a, double b,
                    int norm_type, int rtype, const Mat & mask );
    Rect boundingRect2i( std::vector<Point2i> & points );
    Rect boundingRect2f( std::vector<Point2f> & points );
    void transpose( const Mat & src, Mat & dst );
    void flip(const Mat & src, Mat & dst, int flipCode);
    bool solve( Mat & src, Mat & src2arg, Mat & _dst, int method );
    int cvEstimateRigidTransform( const std::vector<Point2f> & matA, const std::vector<Point2f> & matB, Mat& matM, int full_affine );
    void fastFree(void* ptr);
    void* fastMalloc( size_t size );
    static size_t alignSize(size_t sz, int n)
    {
        return (sz + n-1) & -n;
    }
    static inline int clip(int x, int a, int b)
    {
        return x >= a ? (x < b ? x : b-1) : a;
    }
    inline  NCvTermCriteria  cvTermCriteria( int type, int max_iter, double epsilon )
    {
        NCvTermCriteria t;
        t.type = type;
        t.max_iter = max_iter;
        t.epsilon = (float)epsilon;
        return t;
    }
    class TermCriteria
    {
    public:
        enum
        {
            COUNT=1, 
            MAX_ITER=COUNT, 
            EPS=2 
        };
        TermCriteria();
        TermCriteria(int type, int maxCount, double epsilon);
        TermCriteria(const NCvTermCriteria& criteria);
        operator NCvTermCriteria() const;
        int type; 
        int maxCount; 
        double epsilon; 
    };
    inline TermCriteria::TermCriteria() : type(0), maxCount(0), epsilon(0) {}
    inline TermCriteria::TermCriteria(int _type, int _maxCount, double _epsilon)
    : type(_type), maxCount(_maxCount), epsilon(_epsilon) {}
    inline TermCriteria::TermCriteria(const NCvTermCriteria& criteria)
    : type(criteria.type), maxCount(criteria.max_iter), epsilon(criteria.epsilon) {}
    inline TermCriteria::operator NCvTermCriteria() const
    { return cvTermCriteria(type, maxCount, epsilon); }
    void fillConvexPoly(Mat& img, const Point2i* pts, int npts,
                        const Scalar & color, int lineType=8,
                        int shift=0);
    Mat estimateRigidTransform( std::vector<Point2f> & src, std::vector<Point2f> & dst,
                                    bool fullAffine);
    void warpAffine( const Mat & _src, Mat & dst,
                    const Mat & M0, Size dsize,
                    int flags = 1, int borderType = 0, const Scalar & borderValue = Scalar() );
    void split( Mat& src, std::vector<Mat>& mv);
    void transform( Mat& _src,  Mat& _dst,  Mat& _mtx );
    void transform( std::vector<Point2f>& src,  std::vector<Point2f>& dst,  Mat& m );
    void findNonZero( const Mat & src, Mat & idx );
    MatExpr operator + (const Mat& a, const Mat& b);
    MatExpr operator + (const Mat& a, const Scalar& s);
    MatExpr operator - (const Mat& a, const Mat& b);
	MatExpr operator - (const Mat& a, const Scalar& s);
    MatExpr operator * (const Mat& a, const Mat& b);
    MatExpr operator * (const Mat& a, double s);
    MatExpr operator * (double s, const Mat& a);
    Mat operator < (const Mat& a, const int & b);
    Rect& operator &= ( Rect& a, const Rect& b );
    Rect operator & (const Rect& a, const Rect& b);
    bool operator == (const Rect& a, const Rect& b);
    Rect2f& operator &= ( Rect2f& a, const Rect2f& b );
    Rect2f operator & (const Rect2f& a, const Rect2f& b);
    bool operator == (const Rect2f& a, const Rect2f& b);
    Point2f operator - (const Point2f& a, const Point2f& b);
    Point2i operator - (const Point2i& a, const Point2i& b);
    static inline double norm2f(const Point2f& pt)
    { return sqrt((double)pt.x*pt.x + (double)pt.y*pt.y); }
    static inline double norm2i(const Point2i& pt)
    { return sqrt((double)pt.x*pt.x + (double)pt.y*pt.y); }
    typedef void (*SplitFunc)(const uchar* src, uchar** dst, int len, int cn);
    typedef void (*TransformFunc)( const uchar* src, uchar* dst, const uchar* m, int, int, int );
    typedef int (*SumFunc)(const uchar*, const uchar* mask, uchar*, int, int);
    typedef int (*SumSqrFunc)(const uchar*, const uchar* mask, uchar*, uchar*, int, int);
    typedef void (*MinMaxIdxFunc)(const uchar*, const uchar*, int*, int*, size_t*, size_t*, int, size_t);
    typedef void (*RemapFunc)(const Mat& _src, Mat& _dst, const Mat& _xy,
    const Mat& _fxy, const void* _wtab,
    int borderType, const Scalar& _borderValue);
    typedef void (*ResizeFunc)( const Mat& src, Mat& dst,
    const int* xofs, const void* alpha,
    const int* yofs, const void* beta,
    int xmin, int xmax, int ksize );
    typedef void (*ResizeAreaFastFunc)( const Mat& src, Mat& dst,
    const int* ofs, const int *xofs,
    int scale_x, int scale_y );
    typedef void (*ResizeAreaFunc)( const Mat& src, Mat& dst, const DecimateAlpha* xtab, int xtab_size, const DecimateAlpha* ytab, int ytab_size, const int* yofs);
    typedef void (*PyrFunc)(const Mat&, Mat&, int);
    typedef void (*RemapNNFunc)(const Mat& _src, Mat& _dst, const Mat& _xy,
    int borderType, const Scalar& _borderValue );
}
#endif 
