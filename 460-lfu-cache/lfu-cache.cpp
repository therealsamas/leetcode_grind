
class listnode{
public:
	listnode* next;
    listnode* prev;
	int val,key,freq;
	listnode(int key,int val){
		this->val = val;
		this->key = key;
		next = NULL;
		prev = NULL;
		freq = 1;
	}
};

class lfunode{
public:
	listnode* head;
    listnode* tail;
	int count;
	lfunode(){
		this->head = new listnode(-1,-1);
		this->tail = new listnode(-1,-1);
		head->prev = tail;
		tail->next = head;
		count=0;
	}
};

class LFUCache {
public:
	unordered_map<int,listnode*> hashmap;
	unordered_map<int,lfunode*> freqtable;
	set<int> priorityfreqs;
	int capacity;
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    void movetofirst(int key){
    	listnode* cur = hashmap[key];
    	listnode* prev_n = cur->next;
    	listnode* prev_p = cur->prev;
    	
    	lfunode* prevparent = freqtable[cur->freq];
    	prevparent->count--;
        // cout<<cur->freq<<" : "<<prevparent->count<<endl;
    	// if removing the last node from any freq
    	if(prevparent->count==0){
    		priorityfreqs.erase(cur->freq);
    	}
    	cur->freq++;
    	// check if the current frequency's map exists in the hashtable or not
    	if(freqtable.count(cur->freq)>0){
    		// exists
    		lfunode* newnode = freqtable[cur->freq];
    		listnode* prevofhead = newnode->head->prev;
    		// add the cur to this
    		prevofhead->next = cur;
    		cur->prev = prevofhead;
    		newnode->head->prev = cur;
    		cur->next = newnode->head;
    		newnode->count++;
    	}else{
    		// not exists
    		// initialize a new freq node
    		lfunode* newnode = new lfunode();
    		freqtable[cur->freq] = newnode;
    		// add the cur to this 
    		newnode->tail->next = cur;
    		newnode->head->prev = cur;
    		cur->next = newnode->head;
    		cur->prev = newnode->tail;
	    	newnode->count++;
    	}
    	priorityfreqs.insert(cur->freq);
    	// balance the location from where cur wastaken from
    	prev_n->prev = prev_p;
    	prev_p->next = prev_n;
    }

    int getlfufreq(){
    	if(priorityfreqs.empty()){
    		return -1;
    	}
    	set<int>::iterator it = priorityfreqs.begin();
    	return *it;
    }

    void removelast(){
    	// get the leastfrequent number;
    	int removalfreq = getlfufreq();
    	if(removalfreq==-1){
    		return;
    	}
    	lfunode* remnode = freqtable[removalfreq];
    	remnode->count--;
    	// removing the last node from a freq node
    	if(remnode->count==0){
    		priorityfreqs.erase(removalfreq);
    	}
    	listnode* deln = remnode->tail->next;
    	remnode->tail->next = deln->next;
        // cout<<removalfreq<<endl;
    	// cout<<deln->val<<endl;
    	// cout<<deln->next->val<<endl;
    	deln->next->prev = deln->prev;


    	// remove from hashtable as well;
    	hashmap.erase(deln->key);
    	return;
    }

    int get(int key) {
        if(hashmap.count(key) > 0){
        	movetofirst(key);
        	return hashmap[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
    	//check if the key exists in the hashtable
    	if(hashmap.count(key)>0){
    		//exists, so update the value;
    		hashmap[key]->val = value;
    		movetofirst(key);
    		return;
    	}
    	if(capacity==0){
    		removelast();
    	}else{
            capacity--;
        }
    	// doesnt exist
    	listnode* newnode = new listnode(key,value);
    	// add this node to 1st freq node's head
    	if(priorityfreqs.find(1) == priorityfreqs.end()){
    		//first node
    		lfunode* newn = new lfunode();
    		freqtable[1] = newn;
    		priorityfreqs.insert(1);
    	}
    	listnode* head1 = freqtable[1]->head;
    	listnode* hprev = head1->prev;
    	freqtable[1]->count++;
    	hprev->next = newnode;
    	newnode->prev = hprev;
    	newnode->next = head1;
    	head1->prev = newnode;
    	// add to hashmap
        // cout<<"key: "<<key<<" "<<newnode->freq<<" : "<<freqtable[1]->count<<endl;
    	hashmap[key] = newnode;
    }
};