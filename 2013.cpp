class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> points;

    DetectSquares() {}

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        points[x][y]++;
    }

    int count(vector<int> point) {
        int res = 0;
        int x = point[0], y = point[1];

        if (!points.count(x)) return 0;

        for (auto& [col, colMap] : points) {
            if (col == x) continue; // must be different x to form square

            int d = col - x;

            // Two potential y-sides for square: y + d and y - d
            for (int dy : {d, -d}) {
                int y1 = y + dy;
                if (points[col].count(y) && points[x].count(y1) && points[col].count(y1)) {
                    res += points[col][y] * points[x][y1] * points[col][y1];
                }
            }
        }

        return res;
    }
};
