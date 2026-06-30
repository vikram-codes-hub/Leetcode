class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
       int c=nums[0]+nums[1]+nums[3];
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int j=i+1,k=n-1;
            while(j<k){
    
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(target-sum)<abs(target-c)){
                   c=sum;
                if(c==target)return target;
                }else if(sum>target)k--;
                else j++;
                
            }
        }
        return c;
    }
};