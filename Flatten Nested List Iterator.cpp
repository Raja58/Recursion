// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        26 Nov 2021
//  @Detail  :        Flatten Nested List Iterator (LeetCode)
//  ============================
//  -->

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    
    vector<int> result;
    int idx = 0;
    
    void extract(vector<NestedInteger> &nestedList)
    {
        for(auto &x : nestedList)
            if(x.isInteger())
                result.push_back(x.getInteger());
            else
                extract(x.getList());
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        extract(nestedList);
    }
    
    int next() {
        return result[idx++];
    }
    
    bool hasNext() {
        return idx != result.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
