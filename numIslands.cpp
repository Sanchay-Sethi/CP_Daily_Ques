class Solution {
public:
    void findConnectedIslands(vector<vector<char>>& grid, int i, int j, int r, int c){
        if(i<0 || i>=r || j<0 || j>=c ||grid[i][j]!='1') return;
        grid[i][j] = '2';
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        for(int k = 0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            findConnectedIslands(grid, x, y, r, c);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int noOfRows = grid.size();
        if(noOfRows == 0) return 0;
        int noOfCols = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i<noOfRows; i++){
            for(int j = 0; j<noOfCols; j++){
                if(grid[i][j]=='1'){
                    findConnectedIslands(grid, i, j, noOfRows, noOfCols);
                    ans++;
                }
            }
        }
        return ans;
    }
};
