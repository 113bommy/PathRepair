from sys import stdin, stdout
from collections import defaultdict
import heapq as hq
def get_int(): return int(stdin.readline().strip())
def get_ints(): return map(int,stdin.readline().strip().split()) 
def get_array(): return list(map(int,stdin.readline().strip().split()))
def get_string(): return stdin.readline().strip()
INF=1e10
#for _ in range(int(stdin.readline())):
n,k=get_ints()
h=get_array()
dp=[0]*(n-k+1)
for i in range(k):
    dp[0]+=h[i]
minh=dp[0]
index=0
i=1
for j in range(k,n):
    dp[i]=dp[i-1]+h[j]-h[j-k]
    if dp[i]<minh:
        minh=dp[i]
        index=j-k+1
print(index+1)