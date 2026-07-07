class Solution {
public:
    static bool cmp(pair<char,int> a, pair<char,int> b){
        return a.second < b.second;
    }

    string frequencySort(string s) {
        vector<pair<char,int>> mp(128);

        for(char c : s) {
            mp[c].first = c;
            mp[c].second++;
        }

        sort(mp.begin(), mp.end(), cmp);

        string ans = "";

        for(int i = 127; i >= 0; i--) {
            if(mp[i].second>0){
                int cnt = mp[i].second;

            while(cnt > 0) {
                ans += mp[i].first;
                cnt--;
            }
            }
        }

        return ans;
    }
};