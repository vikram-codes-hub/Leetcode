class LRUCache {
public:
unordered_map<int,pair<list<int>::iterator,int>>mp;
list<int>cache;
int n;
    LRUCache(int capacity) {
         n=capacity;
    }
    void maketofirst(int key){
        cache.erase(mp[key].first);
        cache.push_front(key);
        mp[key].first=cache.begin();
    }

    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            //sbase phele agge dalo usko dll me fhir uske bad uska address chane kro fhir uska value return krdo
            maketofirst(key);
            return mp[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //check ki khai mey presengt to nhi
        if(mp.find(key)!=mp.end()){
            mp[key].second=value;
            maketofirst(key);         
        }else{
            cache.push_front(key);
            mp[key]={cache.begin(),value};
            n--;
        }

        if(n<0){//mtlb  size se ajda exceed kr gyi hai
        int key_to_del=cache.back();
        mp.erase(key_to_del);
        cache.pop_back();
        n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */