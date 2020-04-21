#include<cstdio>
#include<cstring>
#define MAXN 100
using namespace std;

void MergeSort(int* num,int left,int right,int* help){
    if(left + 1 >= right) return;
    int mid = (left + right) / 2;
    MergeSort(num,left,mid,help); //[left,mid)
    MergeSort(num,mid,right,help); //[mid,right)
    int leftIndex = left,rightIndex = mid,index = left;
    while(leftIndex < mid || rightIndex < right){
        //先放右边的
        if(leftIndex >= mid || (rightIndex < right && num[leftIndex] > num[rightIndex])) 
            help[index++] = num[rightIndex++];
        else help[index++] = num[leftIndex++];
    }
    //复制回去
    for(int i = left;i < right;++i){
        num[i] = help[i];
        //printf("%d ",num[i]);
    }
    //printf("\n");
}

int main(void){
    int n = 0;
    int num[MAXN],help[MAXN];
    while(1){
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        memset(help,0,sizeof(help));
        int i = 0;
        while(i < n) scanf("%d",&num[i++]);
        MergeSort(num,0,n,help);
        
        while(--n >= 0) printf("%d ",num[n]);
    }
    return 0;
}

/*
4
4 3 2 1
5
-1 -100 4 3 -50
6
100 20 1 22 33 -100
*/
