const int MAXN = 1e5 + 5;
int tr[MAXN];

// tr[i] = sum{ (i - lowbit(i), i] }
int lowbit(int x){
    return x & -x; // 返回2^k (k就是x末尾0的个数)
}

void add(int u,int v){
    for(int i = u; i <= n; i += lowbit(i)) tr[i] += v;
}

int sum(int u){
    int ret = 0;
    for(int i = u; i; i -= lowbit(i)) ret += tr[i];
    return ret;
}