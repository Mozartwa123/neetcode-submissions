class Solution {
public:
    int maxSubArray(vector<int>& nums) {
	int n = nums.size();
	int m = nums[n - 1];
	int dpi = m;
	for(int i = n - 2; i >= 0; i--){
		if(dpi > 0) dpi += nums[i];
		else dpi = nums[i];
		if(dpi > m) m = dpi;
	}
	return m;

    }
};
