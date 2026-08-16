class Solution {
public:

    bool dfs(int node, int destination,vector<vector<int>>& adj,vector<int>& vis) {

        vis[node] = 1;
             
        if (node == destination) {
            return true;
        }

        for (auto i : adj[node]) {

            if (!vis[i]) {

                if (dfs(i, destination, adj, vis)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        vector<vector<int>> adj(n);

        
        for (auto i : edges) {

            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        return dfs(source, destination, adj, vis);
    }
};