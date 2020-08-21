#include<iostream>
#include<list>
#include<vector>

template<typename hashObj>

class hashTable{
    public:
        explicit hashTable(int size = 101){
            currentSize = 0;
            theLists.resize(size);
        }

        bool contains(const hashObj & rhs)const{
            auto & thelist = theLists[myhash(rhs)];
            return find(thelist.begin(), thelist.end(), rhs) != thelist.end();  
        }
        
        bool insert(const hashObj & rhs){
            auto & thelist = theLists[myhash(rhs)];
            if (find(thelist.begin(), thelist.end(), rhs) != thelist.end())
                return false;

            thelist.push_back(rhs);
            if (++currentSize > theLists.size())
                rehash;

            return true;
        }

        bool insert(hashObj && rhs){
            auto & thelist = theLists[myhash(std::move(rhs))];
            if (find(thelist.begin(), thelist.end(), std::move(rhs)) != thelist.end())
                return false;

            thelist.push_back(std::move(rhs));
            if (++currentSize > theLists.size())
                rehash();

            return true;
        }

        void remove(const hashObj & rhs){
            auto & thelist = theLists[myhash(rhs)];
            auto pos = find(thelist.begin(), thelist.end(), rhs);
            if (pos == thelist.end())
                return true;
            
            thelist.erase(pos);
            --currentSize;
            return true;
        }

        void makeEmpty(){
            for (auto & thelist: theLists)
                thelist.clear();
        }

    private:
        std::vector<std::list<int>> theLists;
        int currentSize;
        void rehash(){
            // 大小要变成两倍
            std::vector<std::list<int>> copy = theLists;
            makeEmpty();
            theLists.resize(2 * currentSize + 1);

            currentSize = 0;
            
            for (const auto & thelist: copy)
                for (const int & el: thelist)
                    insert(std::move(el));
            
        }

        size_t myhash(const hashObj & rhs)const;
};

