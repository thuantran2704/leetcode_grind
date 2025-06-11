class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int mav = 1;

        for(int i = 0 ;i < n;i++){
            while(!pq.empty() && pq.top() <= intervals[i][0]) pq.pop();

            if(pq.size() < mav){
                //check if there still room available. else increase it.

            } else {
                mav++;
            }
            pq.push(intervals[i][1]);
        }
        return mav;
    }
};