/*
爱丽丝和鲍勃继续他们的石子游戏。许多堆石子 排成一行，每堆都有正整数颗石子 piles[i]。游戏以谁手中的石子最多来决出胜负。
爱丽丝和鲍勃轮流进行，爱丽丝先开始。最初，M = 1。
在每个玩家的回合中，该玩家可以拿走剩下的 前 X 堆的所有石子，其中 1 <= X <= 2M。然后，令 M = max(M, X)。
游戏一直持续到所有石子都被拿走。
假设爱丽丝和鲍勃都发挥出最佳水平，返回爱丽丝可以得到的最大数量的石头。

示例 1：

输入：piles = [2,7,9,4,4]
输出：10
解释：如果一开始Alice取了一堆，Bob取了两堆，然后Alice再取两堆。爱丽丝可以得到2 + 4 + 4 = 10堆。如果Alice一开始拿走了两堆，那么Bob可以拿走剩下的三堆。在这种情况下，Alice得到2 + 7 = 9堆。返回10，因为它更大。
示例 2:

输入：piles = [1,2,3,4,5,100]
输出：104

提示：

1 <= piles.length <= 100
1 <= piles[i] <= 104

*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;


class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int s = 0;
        int f[n][n + 1];  
        for (int i = n - 1; i >= 0; --i) {
            s += piles[i];
            for (int m = 1; m <= i / 2 + 1; ++m) {
                if (i + m * 2 >= n) f[i][m] = s;
                else {
                    int mn = INT_MAX;
                    for (int x = 1; x <= m * 2; ++x) {
                        mn = min(mn, f[i + x][max(x, m)]);
                    }
                    f[i][m] = s - mn;
                } 
            }
        }
        return f[0][1];
    }
};


int main() {
    auto s = Solution();
    vector<int> piles {2, 7, 9, 4, 4};
    std::cout << s.stoneGameII(piles) << std::endl;
    return 0;
}