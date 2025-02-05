class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> a;
      int count=0;
      for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]){
            a.push_back(i);
            count++;
        }
      }
      if(count!=2 && count!=0)
        return false; 
    // If count is 0, the strings are already equal, so return true
        if (count == 0) return true;
        int i=a[0];
        int j=a[1];
        swap(s2[i],s2[j]);
        if(s1==s2)
        return true;

        return false;

    }
};