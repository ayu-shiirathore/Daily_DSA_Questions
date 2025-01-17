class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int first=0, last=0;
        for(int i=0;i<derived.size();i++){
            if(derived[i]==1)
            last=~last;
            else last=last;
        }

        return first==last;
    }
};