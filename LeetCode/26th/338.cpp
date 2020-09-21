#include <vector>
using namespace std;

class Solution {
private:
    vector<int> ans;
public:
    vector<int> countBits(int num) {
        ans.resize(num + 1, 0);
        if (num == 0) return ans;
        ans[1] = 1;
        for (int i = 2; i <= num; ){
            int j = i * 2;
            int idx = i;
            
            while (idx < j && idx <= num) {
                ans[idx] = ans[idx - i] + 1;
                idx++;
            }
            i = j;
        }
        return ans;
    }
};