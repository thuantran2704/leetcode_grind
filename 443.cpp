class Solution {
    public:
        int compress(vector<char>& chars) {
            int n = chars.size();
            int res = 0; // write index
            int i = 0;
    
            while (i < n) {
                char current = chars[i];
                int count = 0;
    
                // Count occurrences of the current character
                while (i < n && chars[i] == current) {
                    i++;
                    count++;
                }
    
                // Write the character
                chars[res++] = current;
    
                // Write the count if more than 1
                if (count > 1) {
                    for (char c : to_string(count)) {
                        chars[res++] = c;
                    }
                }
            }
    
            return res;
        }
    };