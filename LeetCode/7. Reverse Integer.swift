//
//  7. Reverse Integer.swift
//  LeetCode
//
//  Created by SunGuoZheng on 7/12/16.
//  Copyright © 2016 SunGuoZheng. All rights reserved.
//

class ReverseInteger {
    func reverse(x: Int) -> Int {
        let max = 2147483647
        let min = -max - 1
        var xx = x
        
        var y = 0, m = 0
        while(xx != 0){
            m = xx%10
            // del m for avoid overfit
            if (y > max/10 || y < min/10)  {
                return 0
            }
            y = y*10 + m
            xx = xx/10
        }
        
//        if x < 0 {
//            y=y*(-1)
//        }

        return y
    }
}

func testRI() {
    let rt = ReverseInteger()
    print(Int.min)
    print(rt.reverse(Int.min))
    print(rt.reverse(123))
    print(rt.reverse(-123))
    print(rt.reverse(1000))
    print(rt.reverse(1534236469))
}
