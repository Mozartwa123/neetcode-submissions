class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
	if(n == 1){
		return s[0] != '0';
	}
	vector<int> dp(n);
	dp[0] = s[0] != '0';
	// printf("%i\n", dp[0]);
	switch (s[0]) {
		case '0':
			dp[1] = 0;
			break;
		case '1':
			dp[1] = s[1] == '0' ? 1 : 2;
			break;
		case '2':
			dp[1] = s[1] == '0' || s[1] > '6' ? 1 : 2;
			break;
		default:
			dp[1] = s[1] == '0' ? 0 : 1;
			break;
	} 
	// printf("%i\n", dp[1]);
	for(int i = 2; i < n; i++){
		int asOneChar = s[i] == '0' ? 0 : dp[i - 1];
		int asTwoChars = 0;
		switch (s[i - 1]) {
			case '0':
				asTwoChars = 0;
				break;
			case '1':
				asTwoChars = dp[i - 2];
				break;
			case '2':
				asTwoChars = s[i] > '6' ? 0 : dp[i - 2];
				break;
			default:
				asTwoChars = 0;
				break;
		}
		dp[i] = asOneChar + asTwoChars;
		// printf("%i\n", dp[i]);
	}
	return dp[n - 1];


    }
};
