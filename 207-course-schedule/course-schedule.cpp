class Solution {
public:

    void solve(vector<vector<int>>& edges, int totalNode,
               unordered_map<int, vector<int>>& adj,
               vector<int>& ans) {

        unordered_map<int, int> indegree;

        queue<int> q;

        // Initialize indegree of all nodes with zero
        for(int i = 0; i < totalNode; i++) {
            indegree[i] = 0;
        }

        // Calculate indegree
        for(auto i : edges) {

            int u = i[1];
            int v = i[0];

            indegree[v]++;
        }

        // Push all nodes having indegree zero
        for(int i = 0; i < totalNode; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS logic
        while(!q.empty()) {

            int frontNode = q.front();

            q.pop();

            // Store processed node
            ans.push_back(frontNode);

            // Update indegree of neighbours
            for(auto nbr : adj[frontNode]) {

                indegree[nbr]--;

                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }

    bool canFinish(int v, vector<vector<int>>& edge) {

        int totalNode = v;

        unordered_map<int, vector<int>> adj;

        for(auto i : edge) {

            int u = i[1];
            int v = i[0];

            adj[u].push_back(v);
        }

        vector<int> ans;

        solve(edge, totalNode, adj, ans);

        if(ans.size() == totalNode) {
            return true;
        }

        return false;
    }
};