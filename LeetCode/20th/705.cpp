class MyHashSet {
private:
    std::vector<std::list<int>> theLists;
    static const int SIZE = 5000;
    int currentSize;
    int myhash(const int & rhs){
        return rhs % theLists.size();
    } 
    
    void makeEmpty(){
        for (auto & thelist: theLists)
            thelist.clear();
    }

    void rehash(){
        std::vector<std::list<int>> copy = theLists;
        makeEmpty();
        theLists.resize(2 * currentSize + 1);
        
        currentSize = 0;

        for (const auto & thelist: copy)
            for (const int & el: thelist)
                add(el);
    }

public:
    /** Initialize your data structure here. */
    MyHashSet() {
        currentSize = 0;
        theLists.resize(SIZE);
    }
    
    void add(int key) {
        auto & thelist = theLists[myhash(key)];
        if (find(thelist.begin(), thelist.end(),key) != thelist.end())
            return;
        thelist.push_back(key);
        if (currentSize++ > theLists.size()) rehash();
    }
    
    void remove(int key) {
        auto & thelist = theLists[myhash(key)];
        auto pos = find(thelist.begin(), thelist.end(), key);
        if (pos == thelist.end()) return;
        thelist.erase(pos);
        --currentSize;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto & thelist = theLists[myhash(key)];
        return find(thelist.begin(), thelist.end(),key) != thelist.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
