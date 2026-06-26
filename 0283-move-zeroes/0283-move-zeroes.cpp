class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==0)return;
       
        int i=0,j=0;
        while(j<nums.size() && nums[j]!=0){
            j++;
            i++;
        }
        
        while(i<nums.size()){
           if(nums[i]==0)i++;
           else{
            swap(nums[i],nums[j]);
            i++;j++;
           } 
        }
    }
};