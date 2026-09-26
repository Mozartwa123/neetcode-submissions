class Solution {
public:
    int maxArea(vector<int>& heights) {
        int j = heights.size() - 1;
	    int i = 0;
	    int maxi = 0;
	    while(i < j){
		    int hi = heights[i];
		    int hj = heights[j];
		    int smhe = hi < hj ? hi : hj;
		    int dist = j - i;
		    int area = dist * smhe;
		    hi < hj ? i++ : j--;
		    if(area > maxi) maxi = area;
	    }
	    return maxi;
    }
};
