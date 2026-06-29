class fenwick_tree {
    int n;
    vector<int> bit;

public:
    fenwick_tree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int i, int val) {
        while (i <= n) {
            bit[i] += val;
            i += (i & -i);
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }

    int rangequery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

class NumArray {
public:
    fenwick_tree fb;
    vector<int> nums;

    NumArray(vector<int>& arr) : fb(arr.size()) {
        nums = arr;

        for (int i = 0; i < arr.size(); i++) {
            fb.update(i + 1, arr[i]);
        }
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        fb.update(index + 1, diff);
    }

    int sumRange(int left, int right) {
        return fb.rangequery(left + 1, right + 1);
    }
};