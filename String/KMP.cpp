#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;

vector<int> next;

void build(const string & pattern){
    int n = pattern.length();
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
        while (j > 0 && text[i] != pattern[j]) j = next[j];
        if (text[i] == pattern[j]) ++j;
        if (j == n) res.push_back(i - n + 1), j = next[j];
    }
    return res;
}

int main(void){

    return 0;
}
