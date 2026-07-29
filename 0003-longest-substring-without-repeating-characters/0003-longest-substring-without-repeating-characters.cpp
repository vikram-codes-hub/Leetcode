class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int mx = 0;

        vector<int> ss(256, 0);

        while (j < n) {
            if (ss[s[j]] == 0) {
                ss[s[j]] = 1;
                mx = max(mx, j - i + 1);
                j++;
            } else {
                ss[s[i]] = 0;
                i++;
            }
        }

        return mx;
    }
};