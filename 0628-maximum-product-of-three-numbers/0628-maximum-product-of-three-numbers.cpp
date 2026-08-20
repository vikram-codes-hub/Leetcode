class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()==3)return nums[0]*nums[1]*nums[2];
        if(nums.size()<=2)return -1;

      int first=INT_MIN,sec=INT_MIN,thi=INT_MIN,minn1=INT_MAX,minn2=INT_MAX;

      int n=nums.size();

      for(int i=0;i<n;i++){
        if(nums[i]>=first){
            thi=sec;
            sec=first;
            first=nums[i];
        }else if(nums[i]<=first && nums[i]>sec){
            thi=sec;
            sec=nums[i];
        }else if(nums[i]<=first && nums[i]<=sec && nums[i]>thi){
            thi=nums[i];
        }

        if(nums[i]<=minn1){
            minn2=minn1;
            minn1=nums[i];
        }else if(nums[i]>=minn1 && nums[i]<minn2){
            minn2=nums[i];
        }
      }

      return max(first*sec*thi,minn1*minn2*first);
    }
};