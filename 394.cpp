class Solution {
    public:
        string decodeString(string s) {
            stack<int> counts;  // To store the number of repetitions
            stack<string> substrings;  // To store previous substrings
            string currentStr = "";
            int currentNum = 0;
            
            for (char c : s) {
                if (isdigit(c)) {
                    currentNum = currentNum * 10 + (c - '0');  // Handling multi-digit numbers
                } else if (c == '[') {
                    // Push the current string and count onto the stacks
                    counts.push(currentNum);
                    substrings.push(currentStr);
                    currentStr = "";  // Reset for the new content inside brackets
                    currentNum = 0;   // Reset the current number
                } else if (c == ']') {
                    // Pop the count and previous string
                    int repeatCount = counts.top();
                    counts.pop();
                    string previousStr = substrings.top();
                    substrings.pop();
                    
                    // Repeat the current string `repeatCount` times and append to the previous string
                    for (int i = 0; i < repeatCount; i++) {
                        previousStr += currentStr;
                    }
                    
                    // Update current string to be the result of this iteration
                    currentStr = previousStr;
                } else {
                    currentStr += c;  // Add the current character to the current string
                }
            }
            
            return currentStr;
        }
    };
    