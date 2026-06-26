class Solution {
public:
    vector<int> temp;

    void merge(vector<int>& arr, int low, int mid, int high) {
        int i = low, j = mid + 1, k = low;

        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= high) {
            temp[k++] = arr[j++];
        }

        for (int x = low; x <= high; x++) {
            arr[x] = temp[x];
        }
    }

    void cntpairs(vector<int>& arr, int low, int mid, int high, int &cnt) {

        int r = mid + 1;

        for (int i = low; i <= mid; i++) {

            while (r <= high &&
                   (long long)arr[i] > 2LL * arr[r]) {
                r++;
            }

            cnt += (r - (mid + 1));
        }
    }

    void mergesort(vector<int>& arr, int low, int high, int &cnt) {

        if (low >= high) return;

        int mid = low + (high - low) / 2;

        mergesort(arr, low, mid, cnt);
        mergesort(arr, mid + 1, high, cnt);

        cntpairs(arr, low, mid, high, cnt);

        merge(arr, low, mid, high);
    }

    int reversePairs(vector<int>& nums) {

        temp.resize(nums.size());

        int cnt = 0;

        mergesort(nums, 0, nums.size() - 1, cnt);

        return cnt;
    }
};