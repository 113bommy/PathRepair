import io, os
import sys 
from sys import stdin

from bisect import bisect_left, bisect_right
from collections import defaultdict, deque, namedtuple
from heapq import heappush, heappop
from math import gcd, ceil, floor, factorial, sqrt
from itertools import combinations, permutations

input = sys.stdin.buffer.readline
# input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# input = sys.stdin.readline

def work():
    ans = 0 

    return 

# sys.setrecursionlimit(200010)
def main():
    test = int(input())

    for idt in range(test):
        n = int(input())
        # n, m = map(int, input().split())
        nums = list(map(int, input().split()))
        a, b = [], []
        for i in range(n):
            if i % 2 == 0:
                a.append(nums[i])
            else:
                b.append(nums[i])

        flag = False 
        for i in a:
            if i in b:
                flag = True 
                break 

        max_gcd1 = a[0]
        for i in range(1, len(a)):
            max_gcd1 = gcd(max_gcd1, a[i])

        max_gcd2 = b[0]
        for i in range(1, len(b)):
            max_gcd2 = gcd(max_gcd2, b[i])
        
        if max_gcd1 == max_gcd2 or flag:
            ans = 0 
        else:
            flag = True
            for i in b:
                if i % max_gcd1 == 0:
                    flag = False 
                    break 
            if flag:
                ans = max_gcd1 
            
            flag = True 
            for i in a:
                if i % max_gcd2 == 0:
                    flag = False 
                    break 
            if flag:
                ans = max_gcd2 
        print(ans)                 
            


    return 


if __name__ == '__main__':
    main()