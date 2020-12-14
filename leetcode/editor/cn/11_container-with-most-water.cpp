//给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, 
//ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。 
//
// 说明：你不能倾斜容器。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：[1,8,6,2,5,4,8,3,7]
//输出：49 
//解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。 
//
// 示例 2： 
//
// 
//输入：height = [1,1]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：height = [4,3,2,1,4]
//输出：16
// 
//
// 示例 4： 
//
// 
//输入：height = [1,2,1]
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// n = height.length 
// 2 <= n <= 3 * 104 
// 0 <= height[i] <= 3 * 104 
// 
// Related Topics 数组 双指针 
// 👍 2048 👎 0


#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        int ptr1 = 0 , ptr2 = height.size()-1;
        while(ptr1 != ptr2){
            int area = (height[ptr1]>height[ptr2]? height[ptr2] : height[ptr1]) * (ptr2 - ptr1);
            if(area > ans) ans = area;
            if(height[ptr1] > height[ptr2]){
                ptr2 -= 1;
            }else{
                ptr1 += 1;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

/* tips：首先明白，容积取决于短板和距离。
 * 如果直接用暴力法会超时，可以用双指针法向中间逼近代替暴力迭代。
 * 分别用两个指针指向容器两端。因为高柱子指针向内移动，距离一定变短，水槽的短板变小或不变，因此容积一定不会变大，所以每次迭代移动短柱子，迭代终止条件是两个指针指向同一位置。
 * */


int main()
{
    Solution s;
    vector<int> data{1,8,6,2,5,4,8,3,7};
    int ans = s.maxArea(data);
    cout<<ans<<endl;
}