class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> Q;
        vector<vector<int> > vis(n, vector<int> (m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    islands++;
                    Q.push({i, j});
                    vis[i][j] = 1;
                    while(!Q.empty()) {
                        pair<int, int> front = Q.front();
                        int x = front.first, y = front.second;
                        if(x-1 >=0 && !vis[x-1][y] && grid[x-1][y] == '1') {
                            Q.push({x-1, y});
                            vis[x-1][y] = 1;
                        }
                        if(x+1 < n && !vis[x+1][y] && grid[x+1][y] == '1') {
                            Q.push({x+1, y});
                            vis[x+1][y] = 1;
                        }
                        if(y-1 >=0 && !vis[x][y-1] && grid[x][y-1] == '1') {
                            Q.push({x, y-1});
                            vis[x][y-1] = 1;
                        }
                        if(y+1 < m && !vis[x][y+1] && grid[x][y+1] == '1') {
                            Q.push({x, y+1});
                            vis[x][y+1] = 1;
                        }
                        Q.pop();
                    }
                }
            }
        }
        return islands;
    }
};