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
    string shortestPalindrome(string s) {
        string k=s;
        reverse(k.begin(),k.end());
        string S=s+"#"+k;
        vector<int>lps=buildLPS(S);
        int i=lps[S.length()-1];
        int left=s.length()-i;
        string ans = s.substr(i, left);
        reverse(ans.begin(),ans.end());
        return ans+s;

    }
};