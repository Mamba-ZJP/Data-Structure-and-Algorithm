class Solution {
private:
    vector<int> ans;
public:
    vector<int> countBits(int num) {
        ans.resize(num + 1, 0);
        if (num == 0) return ans;
        // 利用 /2 其实是二进制右移的特点，来利用已经算过的值，并且看当前最低位是否为1（是否是奇数）
        for (int i = 1; i <= num; i++){
            ans[i] = ans[i >> 1] + (i % 2);
        }
        return ans;

        // ans[1] = 1;
        // for (int i = 2; i <= num; ){
        //     int j = i * 2;
        //     int idx = i;
            
        //     while (idx < j && idx <= num) {
        //         ans[idx] = ans[idx - i] + 1;
        //         idx++;
        //     }
        //     i = j;
        // }
        // return ans;
    }
};
