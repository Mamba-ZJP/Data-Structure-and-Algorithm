#include<vector>
#include<queue>
#include<climits>
#include<cstdio>
using namespace std;

typedef pair<int, int> PII;
// prim 主要思想：一开始随机选个点u作为MST的根，然后更新和u连通的点v距离MST的最近距离: dist[u] = min(dist[u], Euv)。 
// 下一轮选择边，就从剩下的点距离MST最近的边中选一条（剩下的点和MST中任意一点的权值最小的边）
class prim { // O(E log|V|)
    private:
        struct node {
            int code, val;
            node(int c = 0, int v = 0): code(c), val(v) {}
            bool operator < (const node &rhs)const {
                return this->val > rhs.val; // 小顶堆
            }
        };

        vector<vector<PII>> edges; // 有权无向图 邻接表
        priority_queue<node> minHeap;
        vector<int> vis;
        vector<int> dist; // 用一个数组 dis[i] 记录 i 距离 MST（任意一点）最近的距离（权值最小的边的权值）
        int n; // 点的个数

    public:
        prim(vector<vector<PII>> e, int t): edges(move(e)), n(t) {} 

        int solve() {
            int minValSum = 0;
            vis.resize(n + 5, 0); // 都设置为没访问过
            dist.resize(n + 5, INT_MAX);
            minHeap.push(node{1, 0}); // 点是从1开始的

            while (!minHeap.empty()) { // 要选 n-1 条边
                // 贪心地选择还未选择的点里与 MST 中任意一点权值最小的边
                node cur = minHeap.top(); minHeap.pop();
                int u = cur.code;
                if (vis[u]) continue;
                vis[u] = 1;
                minValSum += cur.val;
                
                for (const PII &el: edges[u]){ // 更新
                    int v = el.first;
                    if (vis[v]) continue;
                    if (dist[v] > el.second) { // 当 u和 v 之间的边更短时，就要更新 v 连接生成树(MST)的最短边权值
                        dist[v] = el.second;
                        minHeap.push(node{v, dist[v]});
                    }
                }
            }
            return minValSum;
        }
};
