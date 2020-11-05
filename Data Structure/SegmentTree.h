const int MAXN = 1e5 + 5;

struct node {
    int l, r, sum;
    node(int _l = 0, int _r = 0, int _sum = 0): l(_l), r(_r), sum(_sum) {}
}tr[4 * MAXN];

int n, m, w[MAXN];

void pushup(int rt) { // 利用 rt 的子结点的值更新 rt 的值
    tr[rt].sum = tr[rt << 1].sum + tr[rt << 1 | 1].sum;
}

// 构造线段树，三个参数分别为当前节点，节点保存的左界、右届
void build(int rt, int l, int r) { // 这个函数的 l,r 代表着当前 rt 节点存的范围
    if (l == r) tr[rt] = node(l, r, w[r]);
    else {
        int m = (l + r) >> 1;
        build(rt << 1, l, m);
        build(rt << 1 | 1, m + 1, r);
        // 回溯回来，更新非叶子节点的信息
        tr[rt].l = l, tr[rt].r = r;
        pushup(rt); 
    }
}

// 查询区间和：在以 rt 为根的树里，查询范围为 [l, r]
int query(int rt, int l, int r) { // [l, r] 这个范围里面都需要改，所以更改范围一直为[l, r]
    if (l <= tr[rt].l && tr[rt].r <= r) return tr[rt].sum;
    int m = (tr[rt].l + tr[rt].r) >> 1;
    int res = 0;
    if (l <= m) res += query(rt << 1, l, r);
    if (r > m) res += query(rt << 1 | 1, l, r);
    return res;
}

// 修改操作：在以 rt 为根的树里，查找 index 为 x 的节点，加上v，并且回溯更新所有有关节点的sum
void modify(int rt, int x, int v) { 
    if (tr[rt].l == tr[rt].r) tr[rt].sum += v;
    else {
        int m = (tr[rt].l + tr[rt].r) >> 1;
        // 只去修改和 x 有关的点 x其实是个index
        if (x <= m) modify(rt << 1, x, v);
        else modify(rt << 1 | 1, x, v);
        pushup(rt); // 回溯上来修改rt
    }
}