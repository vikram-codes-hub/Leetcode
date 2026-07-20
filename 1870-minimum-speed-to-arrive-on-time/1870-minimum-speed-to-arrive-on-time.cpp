class Solution {
public:
    bool canPlace(vector<int>& dist, int speed, double hour) {
        double time = 0;

        // First n-1 trains
        for (int i = 0; i < dist.size() - 1; i++) {
            time += ceil((double)dist[i] / speed);
        }

        // Last train
        time += (double)dist.back() / speed;

        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1;
        int r = 10000000;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canPlace(dist, mid, hour)) {
                ans = mid;
                r = mid - 1;   // Try a smaller speed
            } else {
                l = mid + 1;   // Need a higher speed
            }
        }

        return ans;
    }
};