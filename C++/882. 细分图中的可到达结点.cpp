class Solution {
public:
  int reachableNodes(vector<vector<int>>& edges, int M, int N) {
    unordered_map<int, unordered_map<int, int>> g;
    for (const auto& e : edges)
      g[e[0]][e[1]] = g[e[1]][e[0]] = e[2];
    
    priority_queue<pair<int, int>> q;   // {hp, node}, sort by HP desc
    unordered_map<int, int> HP;         // node -> max HP left
    q.push({M, 0});
    while (!q.empty()) {
      int hp = q.top().first;
      int cur = q.top().second;
      q.pop();
      if (HP.count(cur) && HP[cur] > hp) continue;
      HP[cur] = hp;
      for (const auto& pair : g[cur]) {
        int nxt = pair.first;
        int nxt_hp = hp - pair.second - 1;
        if (HP.count(nxt) || nxt_hp < 0) continue;
        q.push({nxt_hp, nxt});
      }
    }
    
    int ans = HP.size(); // Original nodes covered.
    for (const auto& e : edges) {
      int uv = HP.count(e[0]) ? HP[e[0]] : 0;
      int vu = HP.count(e[1]) ? HP[e[1]] : 0;
      ans += min(e[2], uv + vu);
    }
    return ans;
  }
};