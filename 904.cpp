class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            unordered_map<int,int> types;
            int n = fruits.size();
            int ans = 0;
            int i = 0;
            int start = 0;
            //types should be key: fruits value - value: their last seen position., then update start = minimum of that + 1.
            while(i < n){
                if(types.find(fruits[i]) == types.end() && types.size() == 2){
                    int min_index = n;
                    int toremove = -1;
                    for(auto& p: types){
                        if(p.second < min_index){
                            min_index = p.second;
                            toremove = p.first;
                        }
                    }
                    types.erase(toremove);
                    start = min_index + 1;
                }
                types[fruits[i]] = i;
                ans = max(ans, i - start + 1);
                i++;
            }
            return ans;
        }
    };