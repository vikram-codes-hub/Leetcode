class Solution {
public:
vector<int> buildLPS(string pat) {
        vector<int> lps(pat.size(), 0);

        int len = 0;
        int i = 1;

        while (i < pat.length()) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }
    bool repeatedSubstringPattern(string s) {
        vector<int>lps=buildLPS(s);
        int n=lps.size();

      int patternLength = n - lps[n - 1];
     if(patternLength==n)return false;
      return n % patternLength == 0;
    }
};