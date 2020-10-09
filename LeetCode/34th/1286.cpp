#include <iostream>
#include <string>
#include <vector>
#define pub push_back
using namespace std;

class CombinationIterator {
private:
    int cL, len;
    string cha;
    vector<string> res;
    string t;
    int itr;
    void dfs(int dep, int beg) {
        if (dep == cL) {
            res.pub(t);
            cout << t << ' ';
            return;
        }
        if (len - beg < cL - dep) return;
        // if (beg >= len) return;
        for (int i = beg; i < len; i++) {
            t[dep] = cha[i];
            dfs(dep + 1, i + 1);
        }
    }
public:
    CombinationIterator(string cha, int comLen) {
        this->cha = cha, cL = comLen, itr = 0, len = cha.length();
        t = string(cL, ' ');
        dfs(0, 0);
    }
    // 字典序的下一个
    string next() {
        return res[itr++];
    }
    
    bool hasNext() {
        if (itr == res.size()) return false;
        return true;
    }
};