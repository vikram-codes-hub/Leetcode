class LRUCache {
public:
unordered_map<int, pair<list<int>::iterator, int>> cache;
list<int>dll;
int n;
    LRUCache(int capacity) {
    n = capacity;
}

    void makefirst(int key){
       dll.erase(cache[key].first);
        dll.push_front(key);
        cache[key].first=dll.begin();
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            makefirst(key);
            return cache[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            makefirst(key);
            cache[key]={dll.begin(),value};
            return ;
        }

        dll.push_front(key);
        cache[key]={dll.begin(),value};
        n--;

        if(n<0){
            int key_to_del=dll.back();
            cache.erase(key_to_del);
            dll.pop_back();
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