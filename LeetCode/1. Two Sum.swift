//
//  1. Two Sum.swift
//  LeetCode
//
//  Created by SunGuoZheng on 7/12/16.
//  Copyright © 2016 SunGuoZheng. All rights reserved.
//
//
//
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution.
//
// Example:
//  Given nums = [2, 7, 11, 15], target = 9,
//
//  Because nums[0] + nums[1] = 2 + 7 = 9,
//  return [0, 1].
//
// UPDATE (2016/2/13):
//
// The return format had been changed to zero-based indices. Please read the above updated description carefully.
//
// Subscribe to see which companies asked this question

class Solution {
    func twoSum(nums: [Int], _ target: Int) -> [Int] {
        var res = [Int]()
        var dict = [Int:Int]()
        for index in 0 ..< nums.count {
            if dict[target-nums[index]] != nil {
                res.append(dict[target-nums[index]]!)
                res.append(index)
                return res
            }
            else {
                dict[nums[index]] = index
            }
        }
        return res
    }
}



func main() {
    let nums = [2,7,11,15]
    let target = 9
    
    let sol = Solution()
    
    print(sol.twoSum(nums, target))
}
