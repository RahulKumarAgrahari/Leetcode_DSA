class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();    // m rows, n cols
        // Little OPTIMIZATION
        if(k >= (m+n-2))    return m+n-2;
        // If we can remove more obstacles than the shortest dist, the shortest dist will be our answer.        
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(k+1, false)));
        // k+1 because we can have 0 to k obstacles, thus k+1 
        // Using BFS
        int step=0;        
        queue<vector<int>> q;   // {i, j, k}
        q.push({0, 0, k});
        vis[0][0][k] = true;
        vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};   //{down, right, up, left}

        while(!q.empty())   {
            int size = q.size();
            while(size--)   {
                auto t = q.front();     // t = temp
                q.pop();
                if((t[0] == m-1) && (t[1] == n-1)) {
                    return step;
                }                
                for(auto& d: dirs)  {
                    int i = t[0] + d[0];
                    int j = t[1] + d[1];
                    int x = t[2] ;

                    if(i>=0 && i<m && j>=0 && j<n && (x - grid[i][j] >= 0) && !vis[i][j][x- grid[i][j]])  {
                        x -= grid[i][j];
                        vis[i][j][x] = true;
                        q.push({i, j, x});
                    }
                }
            }
            step++;
        }        
        return -1;
    }
};
