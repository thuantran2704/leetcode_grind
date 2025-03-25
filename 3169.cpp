#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Sort the meetings by start time
        sort(meetings.begin(), meetings.end());

        // Merge overlapping meetings
        vector<vector<int>> mergedMeetings;
        for (const auto& meeting : meetings) {
            // If the merged list is empty or no overlap, add the meeting
            if (mergedMeetings.empty() || meeting[0] > mergedMeetings.back()[1]) {
                mergedMeetings.push_back(meeting);
            } else {
                // If there's an overlap, extend the end time of the last meeting
                mergedMeetings.back()[1] = max(mergedMeetings.back()[1], meeting[1]);
            }
        }

        // Calculate the total number of days that have meetings
        int meetingDaysCount = 0;
        for (const auto& m : mergedMeetings) {
            meetingDaysCount += (m[1] - m[0] + 1);
        }

        // Return the days without meetings
        return days - meetingDaysCount;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> meetings1 = {{1, 3}, {2, 5}, {4, 6}};
    int days1 = 7;
    cout << "Test Case 1: " << sol.countDays(days1, meetings1) << " days without meetings" << endl;  // Expected output: 1

    // Test Case 2
    vector<vector<int>> meetings2 = {{1, 2}, {3, 4}, {5, 6}};
    int days2 = 6;
    cout << "Test Case 2: " << sol.countDays(days2, meetings2) << " days without meetings" << endl;  // Expected output: 0

    // Test Case 3
    vector<vector<int>> meetings3 = {{1, 3}, {2, 4}, {3, 5}};
    int days3 = 6;
    cout << "Test Case 3: " << sol.countDays(days3, meetings3) << " days without meetings" << endl;  // Expected output: 1

    // Test Case 4
    vector<vector<int>> meetings4 = {{1, 7}};
    int days4 = 7;
    cout << "Test Case 4: " << sol.countDays(days4, meetings4) << " days without meetings" << endl;  // Expected output: 0

    // Test Case 5
    vector<vector<int>> meetings5 = {{1, 3}, {4, 6}};
    int days5 = 10;
    cout << "Test Case 5: " << sol.countDays(days5, meetings5) << " days without meetings" << endl;  // Expected output: 7

    // Test Case 6
    vector<vector<int>> meetings6 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    int days6 = 5;
    cout << "Test Case 6: " << sol.countDays(days6, meetings6) << " days without meetings" << endl;  // Expected output: 0

    return 0;
}
