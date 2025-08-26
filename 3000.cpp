class Solution {
    public:
        double diaggg(vector<int>& rec){
    return sqrt(1.0 * rec[0] * rec[0] + 1.0 * rec[1] * rec[1]);
        }
        int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
            int area = 0;
            double diag = 0.0;
            for(auto& rec: dimensions){
                double temp = diaggg(rec);
                if(diag < temp){
                    diag = temp;
                    area = rec[0] * rec[1];
                } else if(diag == temp){
                    area = max(area, rec[0] * rec[1]);
                }
            }
            return area;
        }
    };