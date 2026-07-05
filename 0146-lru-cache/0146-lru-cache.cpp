class LRUCache {
public:
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    list<int>dll;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    void makemost(int key){
        //sbse phele address pr jao aur usko remove kr do 
        dll.erase(mp[key].first);
        //ab usko sabse age dal do;
        dll.push_front(key);
        //update address in the map;
        mp[key].first=dll.begin();
    }
    int get(int key) {
        //in this first see if we ahve the value in the amp if not return-1
        if(mp.find(key)!=mp.end()){

            //sbase phele agge le aoo
            makemost(key);
            return mp[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //check if the key is present in the map,if yes we just need tonudpate the address,value  nothing else
        if(mp.find(key)!=mp.end()){
          mp[key].second=value;
          makemost(key);
          return;
        }
        //agr nhi ahi to push kro
        dll.push_front(key);
        mp[key]={dll.begin(),value};
        n--;

        if(n<0){
            int key_to_del=dll.back();
            dll.pop_back();
            mp.erase(key_to_del);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */