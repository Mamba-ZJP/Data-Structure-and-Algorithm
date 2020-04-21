// UVa140 Bandwidth
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 10;
int id[256];
char letter[maxn];

int main() {
  char input[1000];
  while(scanf("%s", input) == 1 && input[0] != '#') {
    // 计算结点个数并给字母编号
    int n = 0;
    for(char ch = 'A'; ch <= 'Z'; ch++) //按照字典序编号
      if(strchr(input, ch) != NULL) { //strchr搜查在串中给定字符的第一个匹配之处，该字符存在于input中
        id[ch] = n++; //字母的编号  n代表一共出现了n个字符（从A到Z中）
        letter[id[ch]] = ch; //利用对应编号 储存字符
      }

    // 处理输入
    int len = strlen(input), p = 0, q = 0;
    vector<int> u, v;//降维 可以使后面处理更简单（但这不是重要的）
    for(;;) {
      while(p < len && input[p] != ':') p++;
      if(p == len) break;
      while(q < len && input[q] != ';') q++;
      for(int i = p+1; i < q; i++) {
        u.push_back(id[input[p-1]]); // 加入起始节点
        v.push_back(id[input[i]]); //加入其邻接点（每个起始结点都对应一个邻接点）
      }
      p++; q++;
    }

    // 枚举全排列
    int P[maxn], bestP[maxn], pos[maxn], ans = n;
    for(int i = 0; i < n; i++) P[i] = i; //最开始的排列 我们只需要关心编号的带宽就可以了，因为letter这个数组存着转换关系
    do {
      for(int i = 0; i < n; i++) pos[P[i]] = i; // 每个编号的位置,以空间换时间
      int bandwidth = 0;
      for(int i = 0; i < u.size(); i++){
        bandwidth = max(bandwidth, abs(pos[u[i]] - pos[v[i]])); // 计算带宽
        if(bandwidth >= ans) break;//prune
      }

      if(bandwidth < ans) {
        ans = bandwidth;
        memcpy(bestP, P, sizeof(P)); //将最优的拷进BestP中
      }
    } while(next_permutation(P, P+n)); //按字典序枚举排列

    // 输出
    for(int i = 0; i < n; i++) printf("%c ", letter[bestP[i]]);
    printf("-> %d\n", ans);
  }
  return 0;
}
