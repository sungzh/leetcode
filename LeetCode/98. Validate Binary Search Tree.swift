//
//  98. Validate Binary Search Tree.swift
//  LeetCode
//
//  Created by guozheng on 8/1/16.
//  Copyright © 2016 SunGuoZheng. All rights reserved.
//


/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:
    
     2
    / \
   1   3
Binary tree [2,1,3], return true.

Example 2:
    
     1
    / \
   2   3
Binary tree [1,2,3], return false.
*/

/*
 * 一开始的思路是比较当前元素是否大于左子树的最大值，是否大于右子树的最小值，有一个不满足就返回false
 * 如果都满足，则递归调用左子树和右子树，判断左子树和右子树是否为二叉搜索树。但这样对于返回true的条件不太好写。而且代码量比较
 * 大
 * 一个简单的思路，就是按顺序将二叉搜索树进行序列化，然后判断这个序列化的数组是不是严格递增的，如果是严格递增，则返回true，如果不是，则返回false
 */

// Definition for a binary tree node.
 public class TreeNode {
     public var val: Int
     public var left: TreeNode?
     public var right: TreeNode?
     public init(_ val: Int) {
         self.val = val
         self.left = nil
         self.right = nil
     }
}

class VBST {
    func isValidBST(root: TreeNode?) -> Bool {
        var stack = [TreeNode]()
        var value = [Int]()
        
        var node = root
        
        // node != nil for the first time
        while(!stack.isEmpty || node != nil) {
            if node != nil {
                stack.append(node!)
                node = node!.left
            }
            else {
                node = stack.removeLast()
                value.append((node?.val)!)
                node = node?.right
            }
            
        }
        // for only one or no element
        if value.count <= 1 {
            return true
        }
        for index in 1...value.count-1 {
            // if equal, also not bst
            if value[index] <= value[index-1] {
                return false
            }
        }
        return true
    }
}

func testVBST() {
    let root = TreeNode(1)
    let l = TreeNode(1)
    root.left = l
    
    let v = VBST()
    print(v.isValidBST(root))
    print(v.isValidBST( nil ))
}
