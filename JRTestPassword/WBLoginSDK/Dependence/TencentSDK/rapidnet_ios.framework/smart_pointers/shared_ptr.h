#pragma once
#include <cstddef>      
#include <algorithm>    
#include <cassert>
namespace smart_pointers = rpdnet;
namespace rpdnet
{
class shared_ptr_count
{
public:
    shared_ptr_count() :
        pn(NULL)
    {
    }
    shared_ptr_count(const shared_ptr_count& count) :
        pn(count.pn)
    {
    }
    void swap(shared_ptr_count& lhs) throw() 
    {
        std::swap(pn, lhs.pn);
    }
    long use_count(void) const throw() 
    {
        long count = 0;
        if (NULL != pn)
        {
            count = *pn;
        }
        return count;
    }
    template<class U>
    void acquire(U* p) 
    {
        if (NULL != p)
        {
            if (NULL == pn)
            {
                pn = new long(1); 
            }
            else
            {
                ++(*pn);
            }
        }
    }
    template<class U>
    void release(U* p, bool is_array) throw() 
    {
        if (NULL != pn)
        {
            --(*pn);
            if (0 == *pn)
            {
                if(is_array)
                {
                    delete[] p;
                }
                else
                {
                    delete p;
                }
                delete pn;
            }
            pn = NULL;
        }
    }
public:
    long*   pn; 
};
template<class T>
class shared_ptr
{
public:
    typedef T element_type;
    shared_ptr(void) throw() : 
        px(NULL),
        pn(),
        is_array_(false)
    {
    }
    explicit shared_ptr(T* p, bool is_allocated_in_array = false) : 
        pn(),
        is_array_(is_allocated_in_array)
    {
        acquire(p);   
    }
    template <class U>
    shared_ptr(const shared_ptr<U>& ptr) throw() : 
        pn(ptr.pn)
    {
        assert((NULL == ptr.px) || (0 != ptr.pn.use_count())); 
        acquire(static_cast<typename shared_ptr<T>::element_type*>(ptr.px));   
        is_array_ = ptr.is_array();
    }
    shared_ptr(const shared_ptr& ptr) throw() : 
        pn(ptr.pn)
    {
        assert((NULL == ptr.px) || (0 != ptr.pn.use_count())); 
        acquire(ptr.px);   
        is_array_ = ptr.is_array();
    }
    shared_ptr& operator=(shared_ptr ptr) throw() 
    {
        swap(ptr);
        return *this;
    }
    inline ~shared_ptr(void) throw() 
    {
        release();
    }
    inline void reset(void) throw() 
    {
        release();
    }
    void reset(T* p) 
    {
        assert((NULL == p) || (px != p)); 
        release();
        acquire(p); 
    }
    void swap(shared_ptr& lhs) throw() 
    {
        std::swap(px, lhs.px);
        pn.swap(lhs.pn);
    }
    inline operator bool() const throw() 
    {
        return (0 < pn.use_count());
    }
    inline bool unique(void)  const throw() 
    {
        return (1 == pn.use_count());
    }
    long use_count(void)  const throw() 
    {
        return pn.use_count();
    }
    inline T& operator*()  const throw() 
    {
        assert(NULL != px);
        return *px;
    }
    inline T* operator->() const throw() 
    {
        assert(NULL != px);
        return px;
    }
    inline T* get(void)  const throw() 
    {
        return px;
    }
    bool is_array() const
    {
        return is_array_;
    }
private:
    inline void acquire(T* p) 
    {
        pn.acquire(p); 
        px = p; 
    }
    inline void release(void) throw() 
    {
        pn.release(px, is_array());
        px = NULL;
    }
private:
    template<class U>
    friend class shared_ptr;
private:
    T*                  px; 
    shared_ptr_count    pn; 
    bool                is_array_;
};
template<class T, class U> inline bool operator==(const shared_ptr<T>& l, const shared_ptr<U>& r) throw() 
{
    return (l.get() == r.get());
}
template<class T, class U> inline bool operator!=(const shared_ptr<T>& l, const shared_ptr<U>& r) throw() 
{
    return (l.get() != r.get());
}
template<class T, class U> inline bool operator<=(const shared_ptr<T>& l, const shared_ptr<U>& r) throw() 
{
    return (l.get() <= r.get());
}
template<class T, class U> inline bool operator<(const shared_ptr<T>& l, const shared_ptr<U>& r) throw() 
{
    return (l.get() < r.get());
}
template<class T, class U> inline bool operator>=(const shared_ptr<T>& l, const shared_ptr<U>& r) throw() 
{
    return (l.get() >= r.get());
}
template<class T, class U> inline bool operator>(const shared_ptr<T>& l, const shared_ptr<U>& r) throw() 
{
    return (l.get() > r.get());
}
template<class T, class U>
shared_ptr<T> static_pointer_cast(const shared_ptr<U>& ptr) 
{
    return shared_ptr<T>(ptr, static_cast<typename shared_ptr<T>::element_type*>(ptr.get()));
}
template<class T, class U>
shared_ptr<T> dynamic_pointer_cast(const shared_ptr<U>& ptr) 
{
    T* p = dynamic_cast<typename shared_ptr<T>::element_type*>(ptr.get());
    if (NULL != p)
    {
        return shared_ptr<T>(ptr, p);
    }
    else
    {
        return shared_ptr<T>();
    }
}
}
