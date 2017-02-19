//
//  21. Merge Two Sorted Lists.swift
//  LeetCode
//
//  Created by SunGuoZheng on 7/12/16.
//  Copyright © 2016 SunGuoZheng. All rights reserved.
//


// 几次错误1. 没有考虑为空情况 2.稍加一个pnext != nil判断 3.rpre?.val <= pnext?.val && pnext?.val <= rnext?.val 忘记加=与判断  2、3导致无线循环
 // Definition for singly-linked list.
// public class ListNode {
//     public var val: Int
//     public var next: ListNode?
//     public init(_ val: Int) {
//         self.val = val
//         self.next = nil
//     }
// }

class MergeTwoSortedLists {
    func mergeTwoLists(l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        if l1 == nil {
            return l2
        }
        if l2 == nil {
            return l1
        }
        var res = l2, rpre =  l2, rnext = l2?.next, pnext = l1
        if l1?.val < l2?.val {
            res = l1
            rpre = l1
            rnext = l1?.next
            pnext = l2
        }
        while(rnext != nil && pnext != nil){
            print(rpre?.val, terminator: "")
            print(rnext?.val, terminator: "")
            print(pnext?.val)
            if rpre?.val <= pnext?.val && pnext?.val <= rnext?.val{
                rpre?.next = pnext
                rpre = pnext
                pnext = pnext?.next
                rpre?.next = rnext
            }
            else if pnext?.val > rnext?.val {
                rpre = rnext
                rnext = rnext?.next
            }
        }
        
        if rnext == nil {
            rnext = pnext
            rpre?.next = rnext
        }
        return res
    }
}

func testMergeTwoSortedLists(){
    let a = ListNode(2)
    let b = ListNode(4)
    let c = ListNode(5)
    let d = ListNode(3)
    let e = ListNode(6)
    let f = ListNode(9)
    a.next = b
    b.next = c
    
    d.next = e
    e.next = f
    let m = MergeTwoSortedLists()
    // printListNode(a)
    // printListNode(d)
    // printListNode( m.mergeTwoLists( a, d ) )
    // print("Test 2")
    let k = ListNode(8)
    printListNode( m.mergeTwoLists( nil, k ) )
    c.next = k
    printListNode(a)
    printListNode(d)
    printListNode( m.mergeTwoLists( a, d ) )
}

func testMergeTwoSortedLists2(){
    let a = ListNode(-10)
    let b = ListNode(-10)
    let c = ListNode(-9)
    let d = ListNode(-4)
    let e = ListNode(1)
    let f = ListNode(6)
    let g = ListNode(6)
    a.next = b
    b.next = c
    c.next = d
    d.next = e
    e.next = f
    f.next = g

    let k = ListNode(-7)
    printListNode(a)
    printListNode(k)
    let m = MergeTwoSortedLists()
 
    printListNode( m.mergeTwoLists( a, k ) )
}

func testMergeTwoSortedLists3(){
    let a = ListNode(-10)
    let b = ListNode(-9)
    let c = ListNode(-6)
    let d = ListNode(-4)
    let e = ListNode(1)
    let f = ListNode(9)
    let g = ListNode(9)
    a.next = b
    b.next = c
    c.next = d
    d.next = e
    e.next = f
    f.next = g
    
    let a1 = ListNode(-5)
    let b1 = ListNode(-3)
    let c1 = ListNode(0)
    let d1 = ListNode(7)
    let e1 = ListNode(8)
    let f1 = ListNode(8)
    a1.next = b1
    b1.next = c1
    c1.next = d1
    d1.next = e1
    e1.next = f1
    printListNode(a)
    printListNode(a1)
    let m = MergeTwoSortedLists()
    
    printListNode( m.mergeTwoLists( a, a1 ) )
}



func printListNode(n: ListNode?){
    var o = n
    print("node")
    while(o != nil) {
        print(o?.val)
        o = o?.next
    }
}
