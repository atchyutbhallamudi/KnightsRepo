class Solution {
public:
    bool ans = true;
    vector<int> col;
    void dfs(int node,int colour,vector<vector<int>>& graph){
        if(col[node]) return;
        col[node] = colour;
        for(auto v : graph[node]){
            if(!col[v]){
                dfs(v,3 - col[node],graph);
            }
            else{
                if(col[v] == col[node]) ans = false;
            }
        }
        return;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        col.assign(n+1,0);
        ans = true;
        for(int i = 0;i<n;i++)if(!col[i])dfs(i,1,graph);
        return ans;
    }
};