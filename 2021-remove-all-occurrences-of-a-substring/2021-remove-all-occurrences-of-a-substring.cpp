class Solution {
public:
    string removeOccurrences(string s, string part) {
        if (s == "") return "";
        
        stack<char> st;
        int n = part.size();
        string check = "";
        
        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);    // Push current character onto the stack
            check += st.top();  // Add the top of the stack to the 'check' string
            
            // If the length of 'check' is at least the size of 'part', check the last 'n' characters
            if (check.size() >= n && check.substr(check.size() - n) == part) {
                // If it matches 'part', pop 'n' characters from the stack
                for (int j = 0; j < n; j++) {
                    st.pop();
                }
                // Remove the last 'n' characters from 'check'
                check = check.substr(0, check.size() - n);
            }
        }

        // Reconstruct the final string from the stack
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;  // Build the string in reverse order
            st.pop();
        }

        return ans;
    }
};
