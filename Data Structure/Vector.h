#include<algorithm>
#include<iostream>
template<typename object>
class vector{
private:
    object * objects;
    int theSize;
    int theCapacity;

public:
    explicit vector(int size = 0):theSize{size}, objects{new object[2 * size + 1]}, theCapacity{2 * size + 1} {}

    vector(const vector & rhs):theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, 
    objects{new object[rhs.theCapacity]}{
        for(int i = 0; i < theSize; ++i) 
            objects[i] = rhs.objects[i];
        std::cout << "1" << std::endl;
    }

    vector & operator = (const vector & rhs){
        vector copy = rhs; //拷贝初始化
        swap(*this,copy); //三次移动
        std::cout << "operator =" << std::endl;
        return *this; //离开作用域后 copy被析构

        //当然这里可以写成拷贝构造那样，先析构原分配的内存，再动态分配新内存，然后再一个一个成员拷贝过来
        //虽然在这里和swap相比，swap没啥优势，
        // 但是如果vector的类数据成员特别多的话，这里的swap就节省了代码量
    }

    vector(vector && rhs):theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{rhs.objects}{
        rhs.objects = nullptr;
        rhs.theSize = rhs.theCapacity = 0;
    }

    vector & operator = (vector && rhs){
        std::swap(objects,rhs.objects);
        std::swap(theSize,rhs.theSize);
        std::swap(theCapacity,rhs.theCapacity);
        // objects = rhs.objects;
        // theSize = rhs.theSize;
        // theCapacity = rhs.theCapacity;
        return *this;
    }

    void swap(vector & lhs, vector & rhs){
        vector copy = std::move(lhs); //移动构造
        lhs = std::move(rhs); //移动赋值
        rhs = std::move(copy); 
    }
    
    ~vector(){
        delete [] objects;
    }

    object & operator [](int pos){
        return objects[pos];
    }

    const object & operator [](int pos) const{
        return objects[pos];
    }

    void push_back(object & x){
        if(theSize == theCapacity) reserve(2 * theCapacity + 1);
        objects[theSize++] = x; 
        // objects[theSize++] = x;
    }

    void push_back(object && x){
        if(theSize == theCapacity) reserve(2 * theCapacity + 1);
        objects[theSize++] = std::move(x); //这里x是右值引用类型，也是一个在内存中的左值，move让它变为一个寄存器里的右值
        
    }

    void resize(int newSize){
        if(newSize <= theCapacity) return;
        reserve(2 * newSize);
        theSize = newSize;
    }

    void reserve(int newCapacity){
        if(newCapacity < theSize) return;

        object * newArray = new object[newCapacity];
        for(int i = 0; i < theSize; ++i)
            newArray[i] = std::move(objects[i]); //移动构造函数
        
        theCapacity = newCapacity;
        std::swap(newArray,objects);
        delete [] newArray;
    }
    
    bool empty() const{
        return theSize == 0;
    }

    void pop_back(){
        --theSize;
    }

    object & back(){
        return objects[theSize - 1];
    }

    const object & back() const{
        return objects[theSize - 1];
    }

    int size() const{
        return theSize;
    }

    int capacity() const{
        return theCapacity;
    }

    typedef object * iterator;
    typedef const object * const_iterator;

    iterator begin(){
        // return & objects[0];
        return objects;
    }

    const_iterator begin() const{
        return & objects[0];
        // return objects;
    }

    iterator end(){
        return & objects[size()];
        // return objects + theSize;
    }

    const_iterator end() const{
        return & objects[size()];
        // return objects + theSize;
    }

};
