import sys
from collections import defaultdict
from itertools import permutations, combinations
import string
from heapq import heapify, heappush, heappop
def solve():
    alphabets = string.ascii_lowercase 
    digits = string.digits
    get_arr = lambda type_=int: list(map(type_, sys.stdin.readline().rstrip('\n').split()))
    inp = lambda type_=int: type_(sys.stdin.readline().rstrip('\n'))
    pair = lambda type_=int: map(type_, sys.stdin.readline().rstrip('\n').split(' '))
    t = inp()
    pairs = []
    for a in range(1, int(1e4)+5):
        for b in range(a, int(1e4)+5, a):
            for c in range(b, int(1e4)+5, b):
                pairs.append((a,b,c))
    for _ in range(t):
        a, b, c = get_arr()
        m = float('inf')
        minpair = (0, 0, 0)
        for a1, b1, c1 in pairs:
            res =  abs(a1-a)+abs(b1-b)+abs(c1-c)
            if res < m:
                m = res
                minpair = (a1, b1, c1)
        print(m)
        print(minpair[0], minpair[1], minpair[2])
solve()




#================================================================================================================ 
# class TreeNode:
    #     def __init__(self, val, start, end):
    #         self.val = val
    #         self.left = None
    #         self.right = None
    #         self.range = (start, end)
    #     def __str__(self):
    #         return self.val

    # class SegTree:
    #     def __init__(self, arr):
    #         self.arr = arr
    #         self.root = self.create_tree(0, len(arr)-1)
    #     def create_tree(self, l, r):
    #         m = (l+r)//2
    #         if l == r:
    #             node = TreeNode(self.arr[l], l, r)
    #             return node
    #         node = TreeNode(0, l, r)
    #         node.left = self.create_tree(l, m)
    #         node.right = self.create_tree(m+1, r)
    #         node.val = node.left.val + node.right.val
    #         return node
    #     def execute_query(self, l, r, node):
    #         a, b = node.range
    #         if l == a and r == b:
    #             return node.val
    #         mid = (a+b)//2
    #         if r <= mid:
    #             return self.execute_query(l, r, node.left)
    #         elif l >= mid+1:
    #             return self.execute_query(l, r, node.right)
    #         else:
    #             return self.execute_query(l, mid, node.left) + self.execute_query(mid+1, r, node.right) 
    #     def update(self, idx, new_val, node):
    #         l, r = node.range
    #         if l == idx and r == idx:
    #             res = new_val - node.val
    #             node.val = new_val
    #             return res
    #         m = (l+r)//2
    #         if idx <= m:
    #             res = self.update(idx, new_val, node.left)
    #         else:
    #             res = self.update(idx, new_val, node.right)
    #         node.val += res
    #         return res
#================================================================================================================ 
