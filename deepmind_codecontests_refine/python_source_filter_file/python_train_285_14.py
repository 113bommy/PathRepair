#!/usr/bin/env python3
import sys
input = sys.stdin.readline
import heapq

class BinaryIndexedTree:
    # Initialize BIT with non-zero value
    def __init__(self, array):
        self.len = len(array)
        self.data = [0] + array
        self.build()

    def build(self):
        for i in range(1, self.len):
            if i + (i & -i) > self.len:
                continue
            self.data[i + (i & -i)] += self.data[i]

    # Add w to a[x] (0-indexed)
    def add(self, x, w):
        x += 1
        while x <= self.len:
            self.data[x] += w
            x += x & -x

    # Get Sum of a[0 : x) (0-indexed)
    def sum(self, x):
        ret = 0
        while x > 0:
            ret += self.data[x]
            x -= x & -x
        return ret

    # Get first index s.t. sum a[0 : index) >= w
    def bisect_left(self, w):
        if w <= 0:
            return 0
        x = 0
        delta = pow(2, (self.len - 1).bit_length())
        while delta > 0:
            if x + delta <= self.len and self.data[x + delta] < w:
                w -= self.data[x + delta]
                x += delta
            delta >>= 1
        return x

t = int(input())
for _ in range(t):
    n = int(input())
    q = []
    base = 0
    left = BinaryIndexedTree([0] * n)
    right = BinaryIndexedTree([0] * n)
    left_bag = [[] for _ in range(n)]
    right_bag = [[] for _ in range(n)]
    for _ in range(n):
        k, l, r = map(int, input().split())
        if k == n:
            base += l
            continue
        if l == r:
            base += l
        elif l > r:
            q.append((l-r, 0, k-1))
            base += r
            left_bag[k-1].append(l-r)
        else:
            q.append((r-l, 1, n-k-1))
            base += l
            right_bag[n-k-1].append(r-l)
    
    left_bag.reverse()
    hq = []
    for bag in left_bag:
        if bag:
            for item in bag:
                heapq.heappush(hq, item)
        if hq:
            base += heapq.heappop(hq) 
    right_bag.reverse()
    hq = []
    for bag in right_bag:
        if bag:
            for item in bag:
                heapq.heappush(hq, item)
        if hq:
            base += heapq.heappop(hq) 
    print(base)