class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end()); // sort to handle duplicates
        vector<bool> used(tiles.size(), false);
        int count = 0;
        dfs(tiles, used, count);
        return count;
    }

private:
    void dfs(const string &tiles, vector<bool> &used, int &count) {
        for (int i = 0; i < tiles.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            count++;
            dfs(tiles, used, count);
            used[i] = false;
        }
    }
};
class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end()); // sort to handle duplicates
        vector<bool> used(tiles.size(), false);
        int count = 0;
        dfs(tiles, used, count);
        return count;
    }

private:
    void dfs(const string &tiles, vector<bool> &used, int &count) {
        for (int i = 0; i < tiles.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            count++;
            dfs(tiles, used, count);
            used[i] = false;
        }
    }
};
