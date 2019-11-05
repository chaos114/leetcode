static bool cmp(pair<int, int>a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}
static bool cmp1(pair<int, int>a, pair<int, int> b) {
	return a.second < b.second;
}
class Solution {
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		vector<pair<int, int>> data;
		for (auto i : envelopes) {
			data.push_back(make_pair(i[0], i[1]));
		}
        sort(data.begin(),data.end(),cmp);
		vector<pair<int, int>> temp;
		for (auto i : data) {
			auto it = lower_bound(temp.begin(), temp.end(), i,cmp1);
			if (it == temp.end()) temp.push_back(i);
			else *it = i;
		}
		return temp.size();
	}
};