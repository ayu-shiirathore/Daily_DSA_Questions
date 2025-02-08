class NumberContainers {
    unordered_map<int,int> indx_num;
    unordered_map<int,set<int>> num_indx;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        //if index is already in use then remove the last number
        if(indx_num.count(index)){
            num_indx[indx_num[index]].erase(index);
            if(num_indx[indx_num[index]].size()==0)
            num_indx.erase(indx_num[index]);
        }
        //insert new number
        indx_num[index]=number;
        num_indx[number].insert(index);        
    }
    
    int find(int number) {
        if(!num_indx.count(number))
        return -1;
        return *(num_indx[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */