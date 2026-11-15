class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int sx = 0, sy = 0;
        int keys = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    sx = i;
                    sy = j;
                }

                if (grid[i][j] >= 'a' &&
                    grid[i][j] <= 'f') {
                    keys++;
                }
            }
        }

        int target = (1 << keys) - 1;

        queue<tuple<int, int, int>> q;

        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(
                n, vector<bool>(1 << keys, false)
            )
        );

        q.push({sx, sy, 0});
        visited[sx][sy][0] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y, mask] = q.front();
                q.pop();

                if (mask == target)
                    return steps;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= m ||
                        ny < 0 || ny >= n ||
                        grid[nx][ny] == '#')
                        continue;

                    char c = grid[nx][ny];
                    int newMask = mask;

                    if (c >= 'A' && c <= 'F') {
                        int bit = c - 'A';

                        if (!(mask & (1 << bit)))
                            continue;
                    }

                    if (c >= 'a' && c <= 'f') {
                        newMask |= (1 << (c - 'a'));
                    }

                    if (!visited[nx][ny][newMask]) {
                        visited[nx][ny][newMask] = true;
                        q.push({nx, ny, newMask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
