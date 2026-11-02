
class Solution {
public:

    void dfs(int src, vector<vector<int>>& rooms,
             unordered_map<int, bool>& visited) {

        visited[src] = true;

        for(auto nbr : rooms[src]) {

            if(!visited[nbr]) {

                dfs(nbr, rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        unordered_map<int, bool> visited;

        int src = 0;

        dfs(src, rooms, visited);

        if(visited.size() == rooms.size()) {
            return true;
        }

        return false;
    }
};
