#include<vector>

class disjointSets{
    private:
        vector<int> fa; // 这里就不写模板(template)了

    public:
        explicit disjointSets(int size = 101): arr(size, -1) {}
        int find(int x) {
            if (fa[x] < 0) 
                return x;
            return fa[x] = find(fa[x]);
        } // 路径压缩

        int find(int x)const { // 找到根是多少
            if (fa[x] < 0) 
                return x;
            return find(fa[x]);
        }

        void unionSets_heigth(int root1, int root2){ // 按高度求并
            if (fa[root1] < fa[root2]) { // root1高
                fa[root2] = root1;
            }
            else {
                if (fa[root1] == fa[root2])
                    fa[root2]--; // 高度+1
                fa[root1] = root2;
            }
        }

        void unionSets_count(int root1, int root2){
            if (fa[root1] < fa[root2]) { // root1多，root2合并
                fa[root1] -= fa[root2];
                fa[root2] = root1;
            }
            else {
                fa[root2] -= fa[root1];
                fa[root1] = root2;
            }
        }
}
