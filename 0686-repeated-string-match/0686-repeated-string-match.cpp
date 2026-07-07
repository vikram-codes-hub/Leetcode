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

    int strStr(string haystack, string needle) {
        vector<int> lps = buildLPS(needle);

        int n = haystack.length();
        int m = needle.length();

        int i = 0, j = 0;

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == m)
                return i - j;

            else if (i < n && haystack[i] != needle[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return -1;
    }

    int repeatedStringMatch(string a, string b) {
        string A = a;
        int cnt = 1;

        // Repeat until A is at least as long as b
        while (A.length() < b.length()) {
            A += a;
            cnt++;
        }

        // First check
        if (strStr(A, b) != -1)
            return cnt;

        // One extra repetition for overlap cases
        A += a;
        cnt++;

        if (strStr(A, b) != -1)
            return cnt;

        return -1;
    }
};