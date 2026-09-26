class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) {
	int n = cost.size();
	vector<int> dp(n);
	int dpi_2 = cost[0];
	int dpi_1 = cost[1];
	for(int i = 2; i < n; i++){
		int temp = dpi_1 < dpi_2 ? dpi_1 + cost[i] : dpi_2 + cost[i];
		dpi_2 = dpi_1;
		dpi_1 = temp;
	}
	return dpi_1 < dpi_2 ? dpi_1 : dpi_2;
}
};
