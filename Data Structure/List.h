#include<algorithm>
#include<iostream>
template<typename object>
class list{

private:
    struct node{
        object data;
        node * prev;
        node * next;
       

        node(const object & d = object{}, node * p = nullptr, node * n = nullptr) //构造函数
        :data(d), prev(p), next(n) {}

        node(object && d, node * p = nullptr, node * n = nullptr) //移动构造
        :data(d), prev(p), next(n) {}
    };

    int theSize;
    node * head;
    node * tail;

    void Ini(){ //只有初始化（构造）的时候才能调用Ini(),否则一个正常状态下的list对象调用会任意改变对象状态
        theSize = 0;  //所以这个是私有成员
        head = new node{};
        tail = new node{};
        head->next = tail;
        tail->prev = head;
    }
    
    class const_iterator{

        protected: //迭代器必须是只有list可以初始化，不能随便拿个指针就初始化了
            friend class list<object>; //list类需要访问cur
            node * cur;
            const_iterator(node * p):cur{p} {}
        
        public:
            const_iterator():cur(nullptr) {}

            const object & operator *() {
                return cur->data;
            }

            const_iterator & operator -- () {
                cur = cur->prev;
                return *this;
            }

            const_iterator  & operator ++ () { //前缀++
                cur = cur->next;
                return *this;
            }

            const_iterator operator ++ (int) { //后缀++要先返回，再移动的
                const_iterator old = *this;
                ++(*this);
                return old;
            }

            bool operator == (const const_iterator & rhs)const {
                return cur == rhs.cur;
            }

            bool operator != (const const_iterator & rhs)const {
                return !(*this == rhs); //用公用操作
            }
            
    };

    class iterator : public const_iterator {
        protected:
            friend class list<object>;
            iterator(node * p): const_iterator{p} {}
        
        public:
            iterator() = default;

            object & operator * () {
                return const_iterator::cur->data;
            }

            const object & operator * ()const { //????
                return const_iterator::cur->data;
            }

            iterator & operator ++ () {
                this->cur = this->cur->next;
                return *this;
            }

            iterator operator ++ (int) {
                iterator old = *this;
                ++(*this);
                return old;
            }

            iterator & operator -- () {
                this->cur = cur->prev;
                return *this;
            }
    };

public:
    list(){
        Ini(); 
    }

    ~list(){
        clear(); delete head; delete tail;
    }

    list(const list & rhs){
        Ini();
        //拷贝rhs中的每一个成员 到 lhs中

        //这里调用push_back的时候，函数里面还会拷贝object的，所以这里就没必要range_for里再拷贝了
        for(auto & x : rhs) push_back(x); //等同于 this->push_back();
    }

    list & operator = (const list & rhs){
        list copy = rhs;
        swap(*this, copy);
        return *this;

        //上面的操作尽量用了公共操作 当然以下做法也可以
        //clear();
        //for(auto & x : rhs) push_back(x);
        //theSize = rhs.theSize;
        //return *this;


        //第一种方法的好处:
        //1.copy离开这个函数作用域之后就会自动析构
        //2.如果rhs的成员特别多，就很麻烦了
    }

    list(list && rhs):theSize{rhs.theSize}, head{rhs.tail}, tail{rhs.tail} {
        rhs.theSize = 0;
        rhs.head = rhs.tail = nullptr; //???为什么这里还可以访问
    }

    list & operator = (list && rhs){ 
        std::swap(theSize, rhs.theSize);
        std::swap(head, rhs.head);
        std::swap(tail, rhs.tail);
        // theSize = rhs.theSize;
        // head = rhs.head; 
        // tail = rhs.tail;
        // rhs.theSize = 0;
        // rhs.head = rhs.tail = nullptr; //???为什么这里还可以访问
        //这里还是在函数内部
        return *this;
    }

    void swap(list & lhs, list & rhs) {
        list copy = std::move(lhs);
        lhs = std::move(rhs);
        rhs = std::move(copy);
    }

    iterator begin(){
        return { head->next };
    }

    iterator  end(){
        return { tail }; //这里返回值不能是左值引用，左值引用不能绑右值
        // iterator t{tail};
        // return t; //不能返回本地变量的引用
    }

    const_iterator begin() const{
        return { head->next };
    }

    const_iterator end() const{
        return { tail };
    }
    
    int size() const {
        return theSize;
    }
    
    int empty() const {
        return theSize == 0;
    }

    void clear(){
        while(!empty()) pop_front();
    }

    //这里都没有任何检查之类的
    object & front(){
        return *begin(); //这里返回iterator也没关系，因为iterator继承了const_..所以可以当成const_用
    }

    const object & front()const {
        return *begin();
    }

    object & back() { //这里--运算符要不要自定义？？？？？？
        return *--end(); //返回类型并不是引用类型
    }

    const object & back ()const {
        return *--end();
    }

    void push_front(const object & x) {
        insert(begin(), x);
    }

    void push_front(object && x) {
        insert(begin(), std::move(x));
    }

    void push_back(const object & x) {
        insert(end(), x);
    }

    void push_back(object && x) {
        insert(end(), std::move(x));
    }

    void pop_front() {
        erase(begin());
    }

    void pop_back() {
        erase(--end());
    }


    //这边迭代器为啥不用引用？？？？？ 调用该函数的实参必须是左值，这里才能是引用
    iterator & insert(iterator itr, const object & x) {
        node * p = itr->cur;
        ++theSize;
        return { p->prev = p->prev->next = new node(x, p->prev, p) };
    }

    iterator insert(iterator  itr, object && x) {
        node * p = itr.cur;
        ++theSize;
        return { p->prev = p->prev->next = new node(std::move(x), p->prev, p) };
    }

    iterator erase(iterator  itr) {
        --theSize;
        node * p = itr.cur;
        node * ret{p->next};
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        return ret;  //这里返回值也不能是引用
    }

    iterator erase(iterator  from, iterator  to) {
        for(iterator itr = from; itr != to;) {
            itr = erase(itr);
        }

        return to;
    }
};
