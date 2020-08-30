#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;

vector<int> next;

void build(const string & pattern){
    int n = pattern.length();
    next.clear();
    next.resize(n + 1);
    int i = -1, j = 0; // j是主串
    next[0] = -1;
    while (j < n){
        if (i == -1 || pattern[i] == pattern[j]){
            ++i, ++j;
            next[j] = i;
        }
        else i = next[i];
    }
}

vector<int> match(const string & text, const string & pattern){
    build(pattern);
    int n = pattern.length();
    vector<int> res;
    for (int i = 0, j = 0; i < n; ++i){
        // j == 0 不需要再跳next数组了，主串需要和0位置再匹配，就要中止循环了, next[0] == -1
        // 找到一个可以匹配的位置，若找不到那么j为0，重新匹配
        while (j > 0 && text[i] != pattern[j]) j = next[j]; 
        // 找不到就要重头开始匹配
        if (text[i] == pattern[j]) ++j;
        // 匹配完成，push主串的可以匹配的起始位置，同样跳next数组, 让前缀相同的部分不用再匹配
        if (j == n) res.push_back(i - n + 1), j = next[j];
    }
    return res;
}
