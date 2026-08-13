class Solution {
public:
vector<int>buildlps(string s){
    int len=0,i=1,m=s.length();
    vector<int>lps(m,0);

   while(i<m){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len!=0){
                len=lps[len-1];
            }else{
                lps[i]=0;
                i++;
                len=0;
            }
        }
    }
    return lps;
}

int kmp(string s,string pat){
    int i=0,j=0;
    vector<int>lps=buildlps(pat);

    int n=s.length(),m=pat.length();
    while(i<n){
        
        if(s[i]==pat[j]){
            i++;j++;
            if(j == m)return i - j;
        }
        else{
            if(j>0){
                j=lps[j-1];
            }else{
                i++;
                j=0;
            }
        }
    }
    return -1;
}
    int strStr(string haystack, string needle) {
        return kmp(haystack, needle);
    }
};