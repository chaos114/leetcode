class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len = rooms.size();
        vector<int> visited(len,0);
        visited[0] = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int curroom = q.front();
            q.pop();
            for(int i = 0;i < rooms[curroom].size();i++){
                if(visited[rooms[curroom][i]]) continue;
                q.push(rooms[curroom][i]);
                visited[rooms[curroom][i]] = 1;
            }
        }
        for(int i = 0;i < len;i++){
            if(visited[i] == 0) return false;
        }
        return true;
    }
};