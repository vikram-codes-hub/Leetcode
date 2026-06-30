class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>st1;
        for(auto i:nums1){
            st1.insert(i);
        }
        set<int>st2;
        for(int i:nums2){
            if(st1.count(i))st2.insert(i);
        }
      vector<int>result;
      for(auto i:st2){
        result.push_back(i);
      }
      return result;
    }
};