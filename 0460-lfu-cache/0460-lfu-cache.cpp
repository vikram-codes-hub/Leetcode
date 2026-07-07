class LFUCache {
public:
struct Node{
    int key;
    int value;
    int freq;
};

int minfreq=0;
int capacity=0;
unordered_map<int,list<Node>::iterator>keynode;
unordered_map<int,list<Node>>freqlist;

    LFUCache(int capacity) {
       this->capacity=capacity;
       minfreq=0; 
    }
    
    int get(int key) {
        if(keynode.find(key)==keynode.end())return -1;
        //sabse phele hame freq ko update krke ++freq me push lrna hai node ko
        auto cc=*(keynode[key]);
        int freq=cc.freq;
        int value=cc.value;

        //sabse phele freqlisdt se removge kro fhir check krop ki kya bo freq emptyy ho gyi hai to usko freqlist se remove kro and then insert
        freqlist[freq].erase(keynode[key]);

        if(freqlist[freq].empty()){
            freqlist.erase(freq);
            if(minfreq==freq)minfreq++;
        }
        freq++;
        freqlist[freq].push_front({key,value,freq});
        keynode[key]=freqlist[freq].begin();
        return value;
    }
    
    void put(int key, int value) {
        if(capacity==0)return;

        // sabse pohel check kro kya keyy alreay present hai kya keynode me
        if(keynode.find(key)!=keynode.end()){
            keynode[key]->value=value;
            get(key);
            return;
        }
        //checkl kro kya size full ho gya hai kya cache ka
        if(keynode.size()==capacity){
            auto &list=freqlist[minfreq];
            int key_to_del=list.back().key;
            list.pop_back();
            if(list.empty()){
                freqlist.erase(minfreq);
            }
            keynode.erase(key_to_del);
        }
        //insert kr do with thje minfreq ko 1 krkew
        minfreq=1;
        freqlist[1].push_front({key,value,1});
        keynode[key]=freqlist[1].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */