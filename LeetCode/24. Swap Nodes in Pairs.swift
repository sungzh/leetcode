//
//  24. Swap Nodes in Pairs.swift
//  LeetCode
//
//  Created by SunGuoZheng on 7/13/16.
//  Copyright © 2016 SunGuoZheng. All rights reserved.
//

//Definition for singly-linked list. 

//public class ListNode {
//    public var val: Int
//    public var next: ListNode?
//    public init(_ val: Int) {
//        self.val = val
//        self.next = nil
//    }
//}

class SwapNodesinPairs {
    func swapPairs(head: ListNode?) -> ListNode? {
        var p = head
        var nhead = head
        var exchange = head
        if head?.next == nil {
            return head
        }
        exchange = p?.next
        p?.next = exchange?.next
        exchange?.next = p
        p = exchange
        exchange = p?.next
        nhead = p
        
        p = exchange?.next
        while(p != nil){
            if p?.next == nil {
                break
            }
            else {
                exchange?.next = p?.next
            }
            exchange = p?.next
            p?.next = exchange?.next
            exchange?.next = p
            exchange = p
            p = p?.next
        }
        return nhead
    }
}

func testSwapNodesinPairs() {
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
    
    let s = SwapNodesinPairs()
    printListNode(s.swapPairs(a))
}
