class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        mp[x]++;
        int fre = mp[x];
        if(st.size() < fre)st.push_back({});
        st[fre - 1].push(x);
    }
    
    int pop() {
        int x = st.back().top();
        st.back().pop();
        if(st.back().empty()) st.pop_back();
        mp[x]--;
        if(mp[x] == 0) mp.erase(x);
        return x;
    }
    vector<stack<int>> st;
    map<int,int> mp;
};