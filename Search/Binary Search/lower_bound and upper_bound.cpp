#include<cstdio>
#include<cstring>
#define MAXN 100
using namespace std;

int lower_bound(int* nums,int left,int right,int val){ //[left,right)
    while(left < right){
        int mid = (left + right) / 2;
        if(nums[mid] >= val) right = mid; //[left,mid)
        else left = mid + 1;
    }
    return left;
}

int upper_bound(int* nums,int left,int right,int val){
    while(left < right){
        int mid = (left + right) / 2;
        if(nums[mid] <= val) left = mid + 1; //[mid,right)
        else right = mid;
    }
    return left;
}

int main(void){
    int n,nums[MAXN];
    while(1){
        scanf("%d",&n);
        memset(nums,0,sizeof(nums));
        int i = 0;
        while(i < n) scanf("%d",&nums[i++]);
        int val; 
        scanf("%d",&val);
       
        printf("so the range of the number %d is [%d,%d)",val,lower_bound(nums,0,n,val),upper_bound(nums,0,n,val));
        break;
    }
    return 0;
}
