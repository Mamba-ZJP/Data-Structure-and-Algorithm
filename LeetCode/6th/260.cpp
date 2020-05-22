class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int s = 0;
        for(int num:nums) s ^= num;
        //因为a^a=0 
//只剩那两个不一样的数字 a ^ b
 //a^b!=0 因为只有相同的数字才为0 所以必定有一位为1，这个就是用来区分他俩
//a^b 结果为1的说明 那些位上 a 和 b 分别为0和1
 //将位中从右往左第一个1保留 其余都设置为0
 //-s = ~s + 1 反码 + 1
 //~s 取反 之后原来右边的第一个1 --> 0，然后+1，但是其他位都是0了
 //这个时候再和原来的s取&，这样也就第一个1不变了
        int diff = (s & (-s));
        vector<int> ans(2,0);
        //初始化为0，因为0^a=a
        for(int num:nums){
        //首先相同的数肯定被分到一组 (因为第k位肯定都是相同的，直接抵消掉)
        //其次 我们这样做主要是为了分离a 和 b
        //a和b中间肯定有一个那一位是0，这样与的话就是0了
            if((num & diff) != 0) ans[0] ^= num;
            else ans[1] ^= num;
        }

        return ans;
    }
};
