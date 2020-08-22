#include<vector>

template<typename hashObj>
class hashTable{
    private:
        static constexpr int EMPTY = 0;
        static constexpr int DELETED = 1;
        static constexpr int ACTIVE = 2;

        struct hashEntry{
            hashObj el;
            int info;
            hashEntry(const hashObj & rhs = hashObj{}, int st = EMPTY): el{rhs}, info{st} {}
            hashEntry(hashObj && rhs, int st = EMPTY): el{rhs}, info{st} {}
        }

        int currentSize;
        vector<hashEntry> arr;
        void rehash(){
            vector<hashEntry> copy = arr;
            makeEmpty();
            arr.resize(copy.size() * 2 + 1);

            for (const auto & ele: copy)
                if (ele.info == ACTIVE)
                    insert(std::move(ele.el));
        }
        
        void makeEmpty(){
            currentSize = 0;
            for (const auto & ele: arr)
                ele.info = EMPTY;
        }

        size_t myhash(const hashObj & rhs)const;

        int findPos(const hashObj & rhs)const { // 关键
            int curPos = myhash(rhs), set = 1;
            while (arr[curPos].info != EMPTY && arr[curPos].el != rhs) { // 循环到要么为空，要么相等（跳过已删除的）
                curPos += set;
                set += 2;

                if (curPos >= arr.size()) 
                    curPos %= arr.size();
            }
            return curPos;
        }

        bool isActive(int pos)const {
            return arr[pos].info == ACTIVE;
        }

    public:
        hashTable(int size = 101): arr(size), currentSize{0} {}
             // resize的时候其实自动初始化了数组里的每个元素

        bool contain(const hashObj & rhs)const {
            int curPos = findPos(rhs);
            return isActive(curPos);
        }

        bool insert(const hashObj & rhs) {
            int curPos = findPos(rhs); // 找到要么空的（插入）， 要么值相等（插入失败）
            if (isActive(curPos))
                return false;

            arr[curPos] = hashEntry{rhs, ACTIVE};

            if (currentSize++ > arr.size())
                rehash();
            return true;
        }

        bool insert(hashObj && rhs) {
            int curPos = findPos(std::move(rhs));
            if (isActive(curPos))
                return false;
                
            arr[curPos] = hashEntry{std::move(rhs), ACTIVE};

            if (currentSize++ > arr.size() / 2)
                rehash();
            return true;
        }

        bool remove(const hashObj & rhs){
            int curPos = findPos(rhs);
            if (!isActive(curPos))
                return false;
            
            arr[curPos].info = DELETED; // 不能置为EMPTY，不然再次调用contain的时候有可能会找不到
            --currentSize;
            return true;
        }
}
