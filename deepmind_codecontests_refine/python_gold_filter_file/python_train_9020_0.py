from collections import defaultdict
from math import inf

n=int(input())
a=[int(x)for x in input().split()]

z=defaultdict(lambda:-1)

dp=[1 for i in range(n) ]
m=-inf
for j in range(n-1,-1,-1):

   # print(z[a[j]],z[a[j]+1])
    if z[a[j]]!=-1:
        dp[j]=max(dp[j],dp[z[a[j]]])
        #print(-1)
    if z[a[j]+1]!=-1:

        dp[j]=max(dp[j],dp[z[a[j]+1]]+1)
        #print(-1)


    z[a[j]]=j
    if m<dp[j]:
        m=dp[j]
        an=j

if m<dp[j]:
    m=dp[j]
    an=j
c=a[an]
x=[]
#print(c)
for i in range(n):
    if a[i]==c:
        c+=1
        x.append(i+1)
print(len(x))
print(*x)


