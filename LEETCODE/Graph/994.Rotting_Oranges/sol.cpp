class Solution {   // store pair of indices and explore neighbors!
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();int col=grid[0].size();
        int arr[row][col]; int c=0; // count no of min
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                arr[i][j]=-1;
            }
        }
        int gl=0; // store flag if a isolated orange remains
        vector<pair<int,int>>index; // store index of rotten
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++) { 
                
                arr[i][j]=0; // fil minutes;
                if(grid[i][j]==2) index.push_back({i,j});

            }
        }int n; 
       
        while(index.size()!=0){
              c++;
              n=index.size();
             
              for(int i=0;i<n;i++){
                  
                  if(index[i].first!=0 && grid[index[i].first -1][index[i].second]==1){
                   grid[index[i].first -1][index[i].second]=2;
                   arr[index[i].first -1][index[i].second]=c; //fill with minutes
                   index.push_back({index[i].first -1,index[i].second});
                
                  }
                   if(index[i].first!=row-1 && grid[index[i].first +1][index[i].second]==1){
                   grid[index[i].first +1][index[i].second]=2;
                   arr[index[i].first +1][index[i].second]=c; //fill with minutes   
                 
                   index.push_back({index[i].first +1,index[i].second});
                  }
                   if(index[i].second!=0 && grid[index[i].first][index[i].second-1]==1){
                     
                   grid[index[i].first][index[i].second-1]=2;
                   arr[index[i].first][index[i].second-1]=c; //fill with minutes
                   index.push_back({index[i].first,index[i].second-1});
                  }
                     if(index[i].second!=col-1 && grid[index[i].first][index[i].second+1]==1){
                         
                   grid[index[i].first][index[i].second+1]=2;
                   arr[index[i].first][index[i].second+1]=c; //fill with minutes
                   index.push_back({index[i].first,index[i].second+1});
                  }
                  
              }
              index.erase(index.begin(),index.begin()+n);
        }
    int lar=INT_MIN; int flg=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
              if(grid[i][j]==1) return -1;
                if(arr[i][j]>lar) lar=arr[i][j];
            }
        }
        return lar;
    }
};
