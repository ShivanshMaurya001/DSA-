
class Solution {
public:

    void solve(vector<vector<int>>& edges, int totalNode,
               unordered_map<int, vector<int>>& adj,
               vector<int>& ans) {

        unordered_map<int, int> indegree;

        queue<int> q;

        for(int i = 0; i < totalNode; i++) {
            indegree[i] = 0;
        }

        for(auto i : edges) {

            int u = i[1];
            int v = i[0];

            indegree[v]++;
        }

        for(int i = 0; i < totalNode; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {

            int frontNode = q.front();

            q.pop();

            ans.push_back(frontNode);

            for(auto nbr : adj[frontNode]) {

                indegree[nbr]--;

                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }

    vector<int> findOrder(int v, vector<vector<int>>& edges) {

        int totalNode = v;

        unordered_map<int, vector<int>> adj;

        for(auto i : edges) {

            int u = i[1];
            int v = i[0];

            adj[u].push_back(v);
        }

        vector<int> ans;

        solve(edges, totalNode, adj, ans);

    
        if(ans.size() == totalNode){
            return ans;
        }
        return {};
    }
};