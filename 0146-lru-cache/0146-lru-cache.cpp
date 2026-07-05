class LRUCache {
public:
unordered_map<int,pair<list<int>::iterator,int>>mp;
list<int>dll;
int n;
    LRUCache(int capacity) {
        n=capacity;  
    }
    void makemostrectn(int key){
    //ye function use kra hue key ko sabse agge le atta haui-->sabse phele key ko delte kro piche se  then key ko agge insert kro then address update kro key ka masp;

    dll.erase(mp[key].first);
    dll.push_front(key);
    mp[key].first=dll.begin();
}
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            makemostrectn(key);
            return mp[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //sbse phele check kya key already present ahi ya nhi map me if yes update the val;ue of it
        if(mp.find(key)!=mp.end()){
            makemostrectn(key);
            mp[key]={dll.begin(),value};
            return;
        }
        //mtlb key present nhi hai to isnert kro fresh
        dll.push_front(key);
        mp[key]={dll.begin(),value};
        n--;

        if(n<0){
           int key_to_delete=dll.back();
            dll.pop_back();
            mp.erase(key_to_delete);
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