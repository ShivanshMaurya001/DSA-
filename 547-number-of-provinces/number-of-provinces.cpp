
class Solution {
public:

    void dfs(int src, vector<vector<int>>& isConnected,
             unordered_map<int, bool>& visited) {

        visited[src] = true;

        int nbrIndex = 0;

        for(auto nbr : isConnected[src]) {

            if(nbr == 1 && !visited[nbrIndex]) {

                dfs(nbrIndex, isConnected, visited);
            }

            nbrIndex++;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int V = isConnected.size();

        unordered_map<int, bool> visited;

        int count = 0;

        for(int src = 0; src < V; src++) {

            if(!visited[src]) {

                count++;
                dfs(src, isConnected, visited);
            }
        }

        return count;
    }
};
