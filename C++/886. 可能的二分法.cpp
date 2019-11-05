class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> G(N);
        for(int i = 0;i < dislikes.size();i++){
            G[dislikes[i][0] - 1].push_back(dislikes[i][1]);
            G[dislikes[i][1]  - 1].push_back(dislikes[i][0]);
        }
        vector<int> mark(N,0);
        queue<int> q;
        for(int i = 0;i <N;i++){
            if(mark[i] != 0) continue;
            mark[i] = 1;
            q.push(i);
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int j : G[cur]){
                    if(mark[j - 1] == mark[cur])return false;
                    if(mark[j - 1] == 0){
                        mark[j - 1] = -mark[cur];
                        q.push(j - 1);
                    }
                    
                }
                
            }
        }
        return true;
    }
};