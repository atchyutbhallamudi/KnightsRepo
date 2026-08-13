class Solution {
public:
    struct UnionFind{
        vector<int> size,par;
        int comps;
        UnionFind(int n){
            size.assign(n+1,1);
            par.resize(n+1);
            comps = n;
            for(int i = 1;i<=n;i++)par[i] = i;
        }
        int find(int x){
            if(par[x] == x) return par[x];
            return par[x] = find(par[x]);
        }

        bool merge(int x, int y){
            x = find(x);
            y = find(y);

            if(x == y) return false;
            if(size[x] < size[y]) swap(x,y);
            
            size[x]+=size[y];
            par[y] = x;
            comps--;
            return true;
        }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.rbegin(),edges.rend());
        int count = 0;
        UnionFind dsu1(n),dsu2(n);
        for(auto v : edges){
            if(v[0] == 3){
                if(dsu1.find(v[1]) != dsu1.find(v[2]) && dsu2.find(v[1]) != dsu2.find(v[2])){
                    dsu1.merge(v[1],v[2]);
                    dsu2.merge(v[1],v[2]);
                    count++;
                }
            }
            else if(v[0] == 2){
                if(dsu2.find(v[1]) != dsu2.find(v[2])){
                    dsu2.merge(v[1],v[2]);
                    count++;
                }
            }
             else if(v[0] == 1){
                if(dsu1.find(v[1]) != dsu1.find(v[2])){
                    dsu1.merge(v[1],v[2]);
                    count++;
                }
            }
        }
        if(dsu1.comps > 1 || dsu2.comps > 1) return -1;
        return edges.size() - count;
    }
};