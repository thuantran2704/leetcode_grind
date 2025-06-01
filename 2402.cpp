class Solution {
public:
    int mostBooked(int room, vector<vector<int>>& meetings) {
        unordered_map<int, int> freq;
        int n = meetings.size();
        priority_queue<int, vector<int>, greater<int>> avail;
        int best_room = 0;
        int best = 0;
        sort(meetings.begin(), meetings.end());
        // end.first is end time, end.second is room number
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> end;
     //end first is end time - room num
        //sort room by start time
        //now begin going through it,
        //check start time, end time, current meeting.
        ///at each iteration (we're considering the meetings one by one)
        //we check if there's a ending that finish before current end time, if yes then keep popping till no more.
        for(int i = 0 ; i < room;i++){
            avail.push(i);
        }
        for(int i = 0 ; i < n;i++){
            long long s = meetings[i][0];
            long ped = meetings[i][1] - s;
            while(!end.empty() && end.top().first <= s){
                pair<int,int> temp = end.top();
                end.pop();
                avail.push(temp.second);
            }
            int room;
            if(avail.empty()){
                //we have no room left at start time
                s = end.top().first;
                room = end.top().second;
                end.pop();
            } else {
                room = avail.top();
                avail.pop();
            }
            freq[room]++;
            if (freq[room] > best || (freq[room] == best && room < best_room)) {
                best = freq[room];
                best_room = room;
            }
            end.push({s+ped,room});
        }
        return best_room;
    }
};