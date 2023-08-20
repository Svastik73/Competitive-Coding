#include <vector>
#include <algorithm> // for std::min
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    int n=triangle.size();
      vector<vector<int>>arr(n,vector<int>(n,0));
      for(int i=0;i<triangle.size();i++){
          for(int j=0;j<=i;j++){
                   arr[i][j]=triangle[i][j];
          }
      }
      for(int i=0;i<n;i++){
          arr[n-1][i]=triangle[n-1][i];
      }
      for(int i=n-2;i>=0;i--){
          for(int j=0;j<=i;j++){
              arr[i][j]=triangle[i][j]+min(arr[i+1][j],arr[i+1][j+1]);
              // find min path lenght from next row's ith column or (i+1)th column!
          }
      }
     return arr[0][0];
    }
};
