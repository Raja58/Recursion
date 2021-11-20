// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        20 Nov 2021
//  @Detail  :        K-th Symbol in Grammar (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1)
            return 0;
        if(k & 1)   //odd i.e,. left child
            return kthGrammar(n - 1, (k + 1) / 2) == 0 ? 0 : 1;
        else    //even i.e., right child
            return kthGrammar(n - 1, k / 2) == 0 ? 1 : 0;
    }
};
