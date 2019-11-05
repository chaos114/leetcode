class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> data;
        for(int i = 0;i < difficulty.size();i++){
            data.push_back({difficulty[i],profit[i]});
        }
        sort(data.begin(),data.end());
        for(int i = 1;i < data.size();i++){
            if(data[i].second < data[i - 1].second) data[i].second = data[i - 1].second;
        }
        int res = 0;
        for(int i = 0;i < worker.size();i++){
            if(worker[i] < data[0].first) continue;
            else if(worker[i] >= data.back().first) res += data.back().second;
            else{
                int left = 0;
                int right = data.size() - 1;
                while(left < right){
                   int mid = (left + right) / 2;
                   if(data[mid].first > worker[i]) right = mid;
                   else left = mid + 1;
                }
                res += data[left - 1].second;
            }
        }
        return res;
    }
};