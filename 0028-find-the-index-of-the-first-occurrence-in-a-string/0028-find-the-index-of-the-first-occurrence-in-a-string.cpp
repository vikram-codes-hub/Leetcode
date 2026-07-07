class Solution {
public:
vector<int>buildlps(string pat){
    vector<int>lps(pat.size(),0);
    int len=0;
    int i=1;
    while(i<pat.length()){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len!=0){
                len=lps[len-1];
            }else {
                len=0;
                i++;
            }
        }
    }
    return lps;
}
    int strStr(string haystack, string needle) {
        vector<int>lps=buildlps(needle);
        int n=haystack.length();
        int m=needle.length();
        int i=0,j=0;
        while(i<n){
         
             if(haystack[i]==needle[j]){
                i++;j++;
            }
                if(j==m)return i-j;
                else{
                    if(i<n && haystack[i]!=needle[j]){
                    if(j!=0){
                        j=lps[j-1];
                    }else i++;
                }
                }
            
          
        }
        return -1;
    }
};