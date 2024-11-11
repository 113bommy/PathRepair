import sys 
# from itertools import
# from collections import deque
# import math
# from bisect import bisect

# input = sys.stdin.buffer.readline
input = sys.stdin.readline
  
q = int(input())
# x = [int(_) for _ in input.split()]

for _ in range(q):
    
    n, m = map(int, input().split())
    print(n,m)
    z = n-m
    x = z//(m+1)
    b = z%(m+1)
    norr = m+1-b
    # b ta x+1 va norr to x
    t = n*(n+1)//2
    bx = b *(x+1)*(x+2)//2
    ax = norr*(x)*(x+1)//2

    print(t-ax-bx)