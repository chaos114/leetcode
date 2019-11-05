// unordered_map
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<int,int> mp;
        unordered_map<int,int> target;
        int len = p.size();
        for(int i = 0;i < len;i++){
            target[p[i]]++;
        }
        int tsize = target.size();
        int cur = 0;
        vector<int> res;
        for(int i = 0;i < s.size();i++){
            if(i < len){
                if(mp[s[i]] == target[s[i]]) cur--;
                mp[s[i]]++;
                if(mp[s[i]] == target[s[i]]) cur++;
            }
            else{
                if(mp[s[i - len]] == target[s[i - len]]) cur--;
                mp[s[i - len]]--;
                if(mp[s[i - len]] == target[s[i - len]]) cur++;
                if(mp[s[i]] == target[s[i]]) cur--;
                mp[s[i]]++;
                if(mp[s[i]] == target[s[i]]) cur++;
            }
            if(cur == tsize) res.push_back(i - len + 1);
        }
        return res;
        
    }
};
//vector less time
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len = p.size();
        vector<int> target(26,0);
        vector<int> cur(26,0);
        for(int i = 0;i < len;i++){
            target[p[i] - 'a']++;
        }
        vector<int> res;
        for(int i = 0;i < s.size();i++){
            if(i >= len) cur[s[i - len] - 'a']--;
            cur[s[i] - 'a']++;
            if(cur == target) res.push_back(i - len + 1);
        }
        return res;
    }
};