class Solution {
    public:
        long long minimumHealth(vector<int>& damage, int armor) {
            long long sum = 0;
            bool used = false;
            int max_dam = 0;
            for(auto& dam: damage){
                sum += dam;
                max_dam = max(max_dam, dam);
            }
            sum -= min(armor, max_dam);
            return sum + 1;
        }
    };