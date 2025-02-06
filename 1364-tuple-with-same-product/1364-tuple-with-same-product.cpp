class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int pro=1;
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                pro=nums[i]*nums[j];
                freq[pro]++;
            }
        }

        int count=0;
        for(auto [product,frequency] : freq){
            count+= 8* nC2(frequency);
        }

        return count;
    }

    int nC2(int n){
        return (n*(n-1))/2;
    }
};