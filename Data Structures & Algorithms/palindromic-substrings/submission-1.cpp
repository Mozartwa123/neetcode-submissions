class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
	if(n == 1){
		return 1;
	}
	vector<int> dp1(n);
	vector<int> dp2(n - 1);
	vector<int> dp3(n - 2);
	int c = n;
	for(int i = 0; i < n; i++) dp1[i] = 1;
	// int len = 1;
	for(int i = 0; i < n - 1; i++) c += (dp2[i] = (s[i] == s[i + 1]));
	// for(int i = 0; i < n - 1; i++) printf("%i ", dp2[i]);
	for(int len = 2; len < n; len++){
		for(int i = 0; i < n - len; i++) c += (dp3[i] = ((dp1[i + 1] == 1) && s[i] == s[i + len]));
		dp1 = dp2;
        dp2 = dp3;
	}
	return c;
    }
};
