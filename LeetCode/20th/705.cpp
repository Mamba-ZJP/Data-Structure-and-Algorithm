class MyHashSet {
private:
    static const int MAXN = 1e6 + 5;
    int hashTable[MAXN];
public:
    /** Initialize your data structure here. */
    // 1e6
    MyHashSet() {
        memset(hashTable, -1, sizeof hashTable);
    }
    
    void add(int key) {
        int pos = key % MAXN;
        if (hashTable[pos] != -1) return;
        hashTable[pos] = key;
    }
    
    void remove(int key) {
        int pos = key % MAXN;
        hashTable[pos] = -1;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int pos = key % MAXN;
        return hashTable[pos] == key;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
