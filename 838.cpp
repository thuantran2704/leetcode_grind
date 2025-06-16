class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        if(n == 1) return dominoes;
        int i = 0;
        stack<int> right;

        while(i < n){
            if(dominoes[i] == 'L'){
                int cur = i - 1;
                if(right.empty()){
                    // Fall left
                    while(cur >= 0 && dominoes[cur] == '.'){
                        dominoes[cur] = 'L';
                        cur--;
                    }
                } else {
                    // Conflict zone R...L
                    int j = right.top() + 1;
                    right.pop();
                    int k = i - 1;
                    while(j < k){
                        dominoes[j] = 'R';
                        dominoes[k] = 'L';
                        j++;
                        k--;
                    }
                }
            } else if(dominoes[i] == 'R'){
                if(!right.empty()){
                    // Continuous R...R
                    int j = right.top() + 1;
                    right.pop();
                    while(j < i){
                        dominoes[j++] = 'R';
                    }
                }
                right.push(i);
            }
            i++;
        }

        // Handle trailing R.... case
        if(!right.empty()){
            int j = right.top() + 1;
            while(j < n && dominoes[j] == '.'){
                dominoes[j++] = 'R';
            }
        }

        return dominoes;
    }
};
