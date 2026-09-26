class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
	vector<int> results(n);
	stack<int> idxs;
	int t;
	for(int i = 0; i < n; i++){
		int todayTemp = temperatures[i];
		while(!idxs.empty() && temperatures[t = idxs.top()] < todayTemp){
			results[t] = i - t;
			idxs.pop();
		}
		idxs.push(i);
	}
	while(!idxs.empty()){
		int t = idxs.top();
		results[t] = 0;
		idxs.pop();
	}
	return results;

    }
};
