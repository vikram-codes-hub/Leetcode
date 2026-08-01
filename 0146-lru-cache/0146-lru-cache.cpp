class LRUCache {
public:
unordered_map<int, pair<list<int>::iterator, int>> cache;
list<int>ll;
int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    void makerecent(int key){
       ll.erase(cache[key].first);
        ll.push_front(key);
        cache[key].first = ll.begin();

    }
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            makerecent(key);
            return cache[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
             makerecent(key);
             cache[key]={ll.begin(),value};
             return;
        }

        ll.push_front(key);
        cache[key]={ll.begin(),value};
        n--;

        if(n<0){
            int key_to_del=ll.back();
            cache.erase(key_to_del);
            ll.pop_back();
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