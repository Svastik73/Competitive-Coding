#include <vector>
#include <algorithm> // for std::min

class Solution {
public:
    int dfs(vector<vector<int>>& triangle, int i, int j) {
        if (i == triangle.size() - 1)
            return triangle[i][j];

        int left = dfs(triangle, i + 1, j);
        int right = dfs(triangle, i + 1, j + 1);

        return triangle[i][j] + min(left, right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty())
            return 0;

        return dfs(triangle, 0, 0);
    }
};
