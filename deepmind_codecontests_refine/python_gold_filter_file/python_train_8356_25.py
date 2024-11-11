import sys;input=sys.stdin.readline
# from itertools import accumulate
# from decimal import *
# import math
# getcontext().prec = 50
# input().strip()
# int(input())
# list(map(int,input().split()))
# map(int,input().split())
# def solve():
# chars = 'abcdefghijklmnopqrstuvwxyz'


# for _ in range(int(input())):
#     solve()    
# print()
# def gcd(a,b):
#     return gcd (b, a % b) if b else a
def solve():
    n= int(input())
    mat = [[0,0,0],
            [2,1,0],
            [4,0,0],
            [1,0,0],
            [0,0,2],
            [0,1,0],
            [2,0,0],
            [0,0,1],
            [1,1,0],
            [3,0,0]]
    digit = n%10
    ans = mat[digit]
    val = 3*ans[0]+5*ans[1]+7*ans[2]
    extra = n-val
    ans[1]+=int(extra/5)
    if ans[1]<0:
        print(-1)
        return
    print(*ans)
# solve()
for _ in range(int(input())):
    solve()    