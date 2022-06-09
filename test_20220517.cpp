#include <iostream>
#include <vector>

using namespace std;

/*你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

 

示例 1：

输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2：

输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 3：

输入：nums = [1,2,3]
输出：3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


int solution(vector<int> list_a){
        int n = list_a.size();
        //if (n < 3){
        //        return 0;
        //}else if(n == 3){
        //        return list_a[1];
        //}
        //int sum1 = list_a[0] + list_a[2];
        //int sum2 = list_a[1] + list_a[3];
        int N = n-1;
        int max_num1 = 0;
        //if(n == 4){
        //        return max(sum1, sum2);
        //}
        //int pre1 = sum1, pre2 = sum1, max_num1=0;
        int pre1 = list_a[1], pre2 = list_a[0];
        for(int i=2; i<N; i++){
                max_num1 = max(pre1, pre2+list_a[i]);
                pre2 = pre1;
                pre1 = max_num1;
        }
        
        pre1 = list_a[2];
        pre2 = list_a[1];
        int max_num2=0;
        
        for(int i=3; i<n; i++){
                max_num2 = max(pre1, pre2+list_a[i]);
                pre2 = pre1;
                pre1 = max_num2;
        }
        return max(max_num1, max_num2);


}

int main(){
        vector<int> list_a = {5,2,3,1,5};
        int res = solution(list_a);
        cout<<res<<endl;
        return 0;
}
