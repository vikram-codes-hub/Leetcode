class fenwick{
    int n;
    vector<int>bit;
    public:

    fenwick(int size){
        n=size;
        bit.assign(n+1,0);
    }

    void update(int i,int val){
        while(i<=n){
            bit[i]+=val;
            i+=i&(-i);
        }
    }

    int sum(int i){
        int sum=0;
        while(i>0){
            sum+=bit[i];
            i-=i&(-i);
        }
        return sum;
    }

};
class Solution {
public:

    int createSortedArray(vector<int>& in) {
        int maxi=0;
        for(auto i:in){
            maxi=max(maxi,i);
        }
        int n=in.size();
        fenwick fb(maxi);
        const int mod = 1e9 + 7;
        
        int cost=0;
        for(int i=0;i<n;i++){
            int mini = fb.sum(in[i]-1);
            int gr=i-fb.sum(in[i]);
            int to_dd=min(gr,mini);
            cost=(cost+to_dd)%mod;
            fb.update(in[i], 1);
        }
        return cost;

    }
};