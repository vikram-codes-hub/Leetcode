class Solution {
public:

int binarys(vector<int>nums,int target){
     int l=0,r=nums.size()-1;

     while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]==target)return mid;
        else if(nums[mid]>target)r=mid-1;
        else l=mid+1;
     }
     return -1;
}
    vector<int> searchRange(vector<int>& nums, int target) {
         if (nums.empty()) return {-1, -1};
       
        int ans=binarys(nums,target);
        if(ans==-1)return {-1,-1};


        vector<int>an(2,0);
        int i=ans,j=ans;
        while (i - 1 >= 0 && nums[i - 1] == target) i--;  // safe bound check
        while (j + 1 < nums.size() && nums[j + 1] == target) j++;
        return {i,j};
    }
};