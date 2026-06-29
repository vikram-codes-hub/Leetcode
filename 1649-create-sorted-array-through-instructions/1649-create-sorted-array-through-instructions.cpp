class fenwick_tree{
    vector<int>bit;
    int n;
    public:
    fenwick_tree(int size){
        n=size;
        bit.assign(n+1,0);
    }

    void update(int i,int val){
        while(i<=n){
            bit[i]+=1;
            i+=i& (-i);
        }
    }

    int query(int i){
        int sum=0;
        while(i>0){
           sum+=bit[i];
           i-=i & (-i); 
        }
        return sum;
    }

    int rangequery(int l,int r){
        return query(r)-query(l-1);
    }
};

class Solution {
public:

    int createSortedArray(vector<int>& in) {
        int maxi=INT_MIN;
        const int mod = 1e9 + 7;
        for(int i=0;i<in.size();i++){
            maxi=max(maxi,in[i]);
        }
        fenwick_tree fen(maxi);
        int n=in.size();
        int cost=0;
        int inserted=0;
        for(int i=0;i<n;i++){
            int smm=fen.query(in[i]-1);
            int greater=inserted-fen.query(in[i]);
            cost+=min(smm,greater);
          cost=cost %mod;
            fen.update(in[i],1);
            inserted++;
        }  
        
        return cost %mod;;
    }
};