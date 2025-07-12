class Solution {
    public:
        int m, n;
        vector<vector<int>> score;
        int maxScore = 0;
    
        int computeScore(vector<int>& student, vector<int>& mentor) {
            int res = 0;
            for (int i = 0; i < n; ++i) {
                if (student[i] == mentor[i]) res++;
            }
            return res;
        }
    
        void dfs(int studentIdx, int usedMask, int currScore, const vector<vector<int>>& students, const vector<vector<int>>& mentors) {
            if (studentIdx == m) {
                maxScore = max(maxScore, currScore);
                return;
            }
    
            for (int i = 0; i < m; ++i) {
                if (!(usedMask & (1 << i))) {
                    dfs(studentIdx + 1, usedMask | (1 << i), currScore + score[studentIdx][i], students, mentors);
                }
            }
        }
    
        int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
            m = students.size();
            n = students[0].size();
            score.assign(m, vector<int>(m, 0));
    
            // Precompute all scores between students and mentors
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    score[i][j] = computeScore(students[i], mentors[j]);
                }
            }
    
            dfs(0, 0, 0, students, mentors);
            return maxScore;
        }
    };
    