//
//  371. Sum of Two Integers.swift
//  LeetCode
//
//  Created by SunGuoZheng on 7/12/16.
//  Copyright © 2016 SunGuoZheng. All rights reserved.
//

class SumofTwoIntegers {
    func getSum(a: Int, _ b: Int) -> Int {
        var x = b
        var y = a
        while(x>0){
            if x%2==1 {
                y=y*2
            }
            x=x/2
        }
        return y
    }
}

func testSumofTwoIntegers() {
    let s = SumofTwoIntegers()
    print(s.getSum(1,2))
    print(s.getSum(4,5))
}
