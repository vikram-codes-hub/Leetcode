class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        if (nums.size() == 1) return 1;

        int n = nums.size();
        int cnt = 1;

        set<int> st;
        set<int> invalid;

        st.insert(nums[0]);

        for (int i = 1; i < n; i++) {

            if (st.find(nums[i]) != st.end()) {

                // New block
                if (nums[i - 1] != nums[i] &&
                    invalid.find(nums[i]) == invalid.end()) {

                    cnt--;
                    invalid.insert(nums[i]);
                }

            } else {
                // First time seeing this number
                st.insert(nums[i]);
                cnt++;
            }
        }

        return cnt;
    }
};