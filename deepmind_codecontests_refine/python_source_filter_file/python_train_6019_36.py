import sys
input=sys.stdin.readline
N=int(input())
C=[int(input())]
for i in range(N-1):
  tmp=int(input())
  if tmp != C[-1]:
    C.append(tmp)
  
import collections
table=collections.defaultdict(int)
N=len(C)
dp=[0]*(N+1)
dp[N]=1
mod=10**9 + 7
for i,x in enumerate(C[::-1]):
  dp[N-1-i]=dp[N-i] + table[x]
  
  dp[N-1-i]%=mod
  table[x]+=d[N-1-i]

print(dp[0])
