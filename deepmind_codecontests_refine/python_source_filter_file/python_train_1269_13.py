
import heapq,math
from collections import defaultdict,deque

import sys, os.path
#sys.setrecursionlimit(10000000)
if(os.path.exists('C:/Users/Dhanush/Desktop/cp/input.txt')):
    sys.stdout = open('C:/Users/Dhanush/Desktop/cp/output.txt', 'w')
    sys.stdin = open('C:/Users/Dhanush/Desktop/cp/input.txt', 'r')

input=sys.stdin.readline

mod=10**9+7
def solve(n):
    dp=[0 for _ in range(n+1)]
    dp[0]=1
    dp[1]=2
    for i in range(2,n):
        dp[i]=(dp[i-1]+dp[i-2])%mod
    return dp[n-1]


r,c=map(int,input().split())
print(((2*(solve(r)-1))%mod)+((2*(solve(c)-1))%mod)+2)