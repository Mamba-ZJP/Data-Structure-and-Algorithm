#include<vector>
#include<queue>
#include<climits>
using namespace std;

typedef pair<int, int> PII;

class prim { // O(E log|V|)
    private:
        struct node {
            int code, val;
            node(int c = 0, int v = 0): code(c), val(v) {}
            bool operator < (const node &rhs)const {
                return this->val < rhs.val;
            }
        };

        vector<vector<PII>> edges; // 有权无向图 邻接表
        priority_queue<node> minHeap;
        vector<int> vis;
        vector<int> dist;
        int n; // 点的个数

    public:
        prim(vector<vector<PII>> e, int t): edges(move(e)), n(t) {} 

        int slove() {
            int minValSum = 0;
            vis.resize(n, 0); // 都设置为没访问过
            dist.resize(n, INT_MAX);
            minHeap.push(node{0, 0});

            while (!minHeap.empty()) { // 要选 n-1 条边
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
