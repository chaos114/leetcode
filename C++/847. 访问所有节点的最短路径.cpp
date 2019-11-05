class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = (1 << n) - 1;
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(1 << n,0));
        for(int i = 0;i < n;i++){
            q.push({i,1 << i});
        }
        int step = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front().first;
                int state = q.front().second;
                q.pop();
                if(state == target) return step;
                if(visited[node][state]) continue;
                visited[node][state] = 1;
                for(int i = 0;i < graph[node].size();i++){
                    q.push({graph[node][i],state | (1 << graph[node][i])});
                }
            }
            ++step;
        }
        return -1;
    }
};
