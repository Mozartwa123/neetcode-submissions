class Solution {
public:
    int halfPalinLen(string s, int m1, int m2, int n){
	int i = m1;
	int j = m2;
	int hplen = 0;
	while(i >= 0 && j < n && s[i--] == s[j++]) hplen++;
	return hplen;
}

string longestPalindrome(string s) {
	int n = s.length();
	int maxplen = 0;
	int maxi = 0;
	for(int i = 0; i < n; i++){
		// even case
		int hplen1 = halfPalinLen(s, i, i + 1, n);
		if(hplen1 * 2 > maxplen){
			maxplen = hplen1 * 2;
			maxi = i - hplen1 + 1; 
		}
		// odd case
		hplen1 = halfPalinLen(s, i, i, n);
		if(hplen1 * 2 - 1 > maxplen){
			maxplen = hplen1 * 2 - 1;
			maxi = i - hplen1 + 1;
		}
	}
	// printf("%i %i\n", maxplen, maxi);
	return s.substr(maxi, maxplen);
}

};
