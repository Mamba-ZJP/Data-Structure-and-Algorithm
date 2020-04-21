// iterative binary search

#include<cstdio>
#include<cstring>
#define MAXN 100
using namespace std;


int binary_search(int* num,int left,int right,int val){
    while(left < right){ //临界调节的设定 其实只要依据一开始的搜索范围即可 究竟是[left,right]还是[left,right)
                   //如果是前者那么left <= right,因为left可以等于right
        int mid = (right + left) / 2; //!!!mid问题
        if(num[mid] == val) return mid;
        else if(num[mid] < val) left = mid + 1; //[mid + 1,right)
        else right = mid;  //[left,mid)
    }
    return -1;
}

int main(void){
    int n,num[MAXN];
    while(1){
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        int i = 0;
        while(i < n) scanf("%d",&num[i++]);
        int val; 
        scanf("%d",&val);
        printf("%d",binary_search(num,0,n,val));
    }

    return 0;
}

/*
7
1 2 3 4 11 12 20
12

*/
