#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Case-insensitive + vowel masking
    string devowel(const string& s) {
        string temp = s;
        for (char &c : temp) {
            c = tolower((unsigned char)c);
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                c = '*';
        }
        return temp;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelMasked;

        // build dictionaries, keep first occurrence only
        for (auto& word : wordlist) {
            string lower = word;
            for (char &c : lower) c = tolower((unsigned char)c);

            if (!caseInsensitive.count(lower))
                caseInsensitive[lower] = word;

            string masked = devowel(word);
            if (!vowelMasked.count(masked))
                vowelMasked[masked] = word;
        }

        vector<string> ans;
        for (auto& q : queries) {
            if (exact.count(q)) {                  // rule 1
                ans.push_back(q);
                continue;
            }

            string lower = q;
            for (char &c : lower) c = tolower((unsigned char)c);

            if (caseInsensitive.count(lower)) {    // rule 2
                ans.push_back(caseInsensitive[lower]);
                continue;
            }

            string masked = devowel(q);
            if (vowelMasked.count(masked)) {       // rule 3
                ans.push_back(vowelMasked[masked]);
                continue;
            }

            ans.push_back("");                     // rule 4
        }
        return ans;
    }
};

