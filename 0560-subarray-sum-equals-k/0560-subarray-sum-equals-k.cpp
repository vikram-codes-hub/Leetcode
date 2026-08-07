class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;//sum,cnt;

        int sum=0;
        mp[0]=1;
        int cnt=0;

        int  n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int tof=sum-k;
            if(mp.find(tof)!=mp.end()){
                cnt+=mp[tof];
            }
            mp[sum]++;   
        }
        return cnt;
    }
};