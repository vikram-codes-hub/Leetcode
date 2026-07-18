class Solution {
public:
    int mySqrt(int x) {
        int l=0,h=x,ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
             long long sqq = 1LL * mid * mid;
            if(sqq==x)return mid;
            else if(sqq<x){
                ans=mid;
                l=mid+1;
            }else h=mid-1;
        }
        return ans;
    }
};