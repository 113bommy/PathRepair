import sys 
from sys import stdin

from bisect import bisect_left, bisect_right
from collections import defaultdict, deque, namedtuple
from math import gcd, ceil, floor
from itertools import combinations, permutations

# https://codeforces.com/contest/1574/problem/B
def main():
    test = int(input())

    for idt in range(test):
        a, b, c, m = map(int, input().split())
        ca = a - 1 
        cb = b - 1 
        cc = c - 1 
        if ca + cb + cc < m:
            print("NO")
            continue
        if ca + cb + cc == m:
            print("YES")
            continue
        
        nums = [a, b, c]
        nums.sort(reverse=True)
        if nums[0] >= nums[1] + nums[2]:
            nums[0] -= (nums[1] + nums[2])
            if nums[0] - 1 > m:
                print("NO")
            else:
                print("YES")
        else:
            print("YES")

    return 


if __name__ == '__main__':
    main()