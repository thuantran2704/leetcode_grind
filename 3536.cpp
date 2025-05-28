class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int,vector<int>, greater<int>> pq;
        while(n > 0){
            pq.push(n%10);
            if(pq.size() > 2) pq.pop();
            n/=10;
        }
        int t1 = pq.top();
        pq.pop();
        int t2 = pq.top();
        return t1 * t2;
    }
};