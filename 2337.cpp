class Solution {
public:
    bool canChange(string start, string target) {
        string t1 = "";
        string t2 = t1;
        int n = start.size();
        vector<int> v1,v2;
        if(target.size() != n) return false;
        for(int i = 0 ; i < n;i++){
            if(start[i] == 'L'){
                t1 += "0";
                v1.push_back(i);
            } else if(start[i] == 'R'){
                t1 += "1";
                v1.push_back(i);
            }
            if(target[i] == 'L'){
                t2 += "0";
                v2.push_back(i);
            } else if(target[i] == 'R'){
                t2 += "1";
                v2.push_back(i);
            }
        }
        if(t1 == t2){
            n = t1.size();
            for(int i = 0; i < n;i++){
                if(t1[i] == '0'){
                    if(v1[i] < v2[i]) return false;
                } else {
                    if(v1[i] > v2[i]) return false;
                }
            }
            return true;
        } else return false;
    }
};