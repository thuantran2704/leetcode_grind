class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int count = 0;
            int n= colors.size();
            int prev = -1;
            for(int i = n-k+1 ; i < n;i++){
                if(colors[i]!= prev) count++;
                else count = 1;
                prev = colors[i];
            }
            int points = 0;
            for(int i = 0 ; i < n;i++){
                if(colors[i] != prev) count++;
                else count = 1;
                prev = colors[i];
                if(count >= k) points++;
            }
            return points;
        }
    };