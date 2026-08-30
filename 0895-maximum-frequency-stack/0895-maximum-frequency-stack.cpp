class FreqStack {
public:

    priority_queue<tuple<int, int, int>> pq;
    unordered_map<int, int> mp;

    int time;

    FreqStack() {
        time = 0;
    }

    void push(int val) {

        mp[val]++;

        pq.push({mp[val], time, val});

        time++;
    }

    int pop() {

        while (true) {

            auto [freq, t, val] = pq.top();
            pq.pop();

           
            if (freq == mp[val]) {

                mp[val]--;

                return val;
            }
        }
    }
};