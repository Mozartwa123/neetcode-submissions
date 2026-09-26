class Solution {
public:
    int robhelp(vector<int>& nums, int b, int e) {
	int n = e - b + 1;
	vector<int> dp(n);
	// dp[i] największy łup z domów 0...i
	// dom nr 0 jest "pusty"
	if(n == 1)
		return nums[b];
	dp[0] = nums[b];
	dp[1] = max(nums[b], nums[b + 1]);
	// printf("dp[0]: %i\n", dp[0]);
	// printf("dp[1]: %i\n", dp[1]);
	for(int i = b + 2, j = 2; i <= e; i++, j++){
		dp[j] = max(nums[i] + dp[j - 2], dp[j - 1]);
		// printf("dp[%i]: %i\n", i, dp[j]);

	}
	return dp[n - 1];
}
int rob(vector<int>& nums) {
	int n = nums.size();
	if(n == 1){
		return nums[0];
	}
	return max(robhelp(nums, 0, n - 2), robhelp(nums, 1, n - 1));
}

};
