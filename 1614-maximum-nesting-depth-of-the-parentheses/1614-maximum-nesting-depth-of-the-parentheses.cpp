class Solution {
public:
    int maxDepth(string s) {
        int maxi=0,i=0,n=s.length(),cnt=0;

        while(i<n){
            if(s[i]=='('){
                cnt+=1;
                maxi=max(maxi,cnt);
            }else if(s[i]==')')cnt-=1;

            i++;
        }
        return maxi;
    }
};

//( ->+1  )->-1   we will have the maxi varibale to hold the count for maximum brackets 