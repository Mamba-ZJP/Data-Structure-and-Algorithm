// 给定一个数列，求解逆序对的个数。
// 逆序对:i < j && num[i] > num[j]

#include<cstdio>
#include<cstring>
#define MAXN 100
using namespace std;

int n,ans;

void solve(int* num,int left,int right,int* help){
    if(left + 1 >= right) return;
    int mid = left + (right - left) / 2;
    solve(num,left,mid,help);
    solve(num,mid,right,help);
    int leftIndex = left,rightIndex = mid,index = left;
    while(leftIndex < mid || rightIndex < right){
        if(leftIndex >= mid || (rightIndex < right && num[rightIndex] < num[leftIndex])){
            help[index++] = num[rightIndex++];
            ans += (mid - leftIndex); //此时 都是 i < j && num[i] > num[j]的 
        }
        else
            help[index++] = num[leftIndex++];
    }
    for(int i = left;i < right;++i)
        num[i] = help[i];
}

int main(void){
    int num[MAXN],help[MAXN];
    while(1){
        scanf("%d",&n);
        ans = 0;
        memset(num,0,sizeof(num));
        memset(help,0,sizeof(help));
        int i = 0;
        while(i < n) scanf("%d",&num[i++]);
        solve(num,0,n,help);
        printf("%d",ans);
    }
    return 0;
}
