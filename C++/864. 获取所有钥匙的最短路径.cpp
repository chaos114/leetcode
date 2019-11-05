class Solution {
public:
  int shortestPathAllKeys(vector<string>& grid) {
    int m = grid.size();
    int n = grid[0].size();    
    int all_keys = 0;
    queue<int> q;
    vector<vector<vector<int>>> seen(m, vector<vector<int>>(n, vector<int>(64, 0)));
        
    // Init
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        const char c = grid[i][j];
        if (c == '@') {
          q.push((j << 16) | (i << 8));
          seen[i][j][0] = 1;
        } else if (c >= 'a' && c <= 'f') {
          all_keys |= (1 << (c - 'a'));
        }
      }
    
    const vector<int> dirs{-1, 0, 1, 0, -1};
    
    int steps = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int s = q.front(); q.pop();
        int x = s >> 16;
        int y = (s >> 8) & 0xFF;
        int keys = s & 0xFF;        
        if (keys == all_keys) return steps;
        for (int i = 0; i < 4; ++i) {
          int nkeys = keys;
          int nx = x + dirs[i];
          int ny = y + dirs[i + 1];          
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          const char c = grid[ny][nx];          
          if (c == '#') continue; // Wall
          // Do not have the key.
          if (c >= 'A' && c <= 'F' && !(keys & (1 << (c - 'A')))) continue;
          // Update the keys we have.
          if (c >= 'a' && c <= 'f') nkeys |= (1 << (c - 'a'));
          if (seen[ny][nx][nkeys]) continue;
          q.push((nx << 16) | (ny << 8) | nkeys);
          seen[ny][nx][nkeys] = 1;
        }
      }
      ++steps;
    }
    return -1;
  }
};