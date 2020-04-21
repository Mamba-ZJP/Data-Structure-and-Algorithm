#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int n;
int capacity[4];
struct state{
    int bottle[3];
    int dist;
    state():dist(0){
        memset(bottle,0,sizeof(bottle));
    }
    bool operator < (const state& t) const{
        return dist > t.dist;
    }
};

int vis[200][200];
int ans[200];

void update_ans(const state& cur){
    for(int i = 0;i < 3;++i){
        int d = cur.bottle[i];
        if(ans[d] == -1 || ans[d] > cur.dist) ans[d] = cur.dist;
    }
}

void bfs(){
    priority_queue<state> min_heap; //min_heap
    state Ini; 
    Ini.bottle[2] = capacity[2];
    min_heap.push(Ini);
    vis[0][0] = 1;
    memset(ans,-1,sizeof(ans)); //初始化为-1，代表没被取到过

    while(min_heap.size()){
        state cur = min_heap.top();
        min_heap.pop();
        update_ans(cur);
        if(ans[capacity[3]] >= 0) break;
            
        for(int i = 0;i < 3;++i){
            for(int j = 0;j < 3;++j){
                if(j == i) continue; //cannot fill itself
                state next = cur;
                int amount = min(cur.bottle[i],capacity[j] - cur.bottle[j]);
                next.bottle[i] -= amount;
                next.bottle[j] += amount;
                next.dist += amount;
                if(!vis[next.bottle[0]][next.bottle[1]]){
                    vis[next.bottle[0]][next.bottle[1]] = 1;
                    min_heap.push(next);
                }
            }
        }
    }
    
    int i = capacity[3];
    while(i > 0){
        if(ans[i] >= 0){
            printf("%d %d\n",ans[i],i);
            return;
        }
        i--;
    }
}

int main(void){
    scanf("%d",&n);
    while(n--){
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d%d",&capacity[0],&capacity[1],&capacity[2],&capacity[3]);
        bfs();
    }
    return 0;
}

/*
2
2 3 4 2
96 97 199 62

output:
2 2
9859 62
*/
