class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        unordered_map<int,vector<int>>adj;
        

        for(auto i : edges){

            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>ans;

        queue<int>q;
        unordered_map<int,int>vis;

        q.push(source);
        vis[source] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for(auto nbr : adj[front]){

                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr] = true;
                }
            }

        }
        int count = 0;
        for(int i = 0; i<ans.size(); i++){

            if(ans[i] == source){
                count++;
            }
            if(ans[i]== destination ){
                count++;
            }
        }

        if(count < 2){
            return false;
        }
        return true;
        
    }
};
