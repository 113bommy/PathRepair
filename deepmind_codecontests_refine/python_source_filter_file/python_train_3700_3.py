from collections import *
n=int(input())
c,s,ans=Counter(),0,n-1
for x in map(int,input().split()):
  s+=x
  c[x]+=1
  ans=min(ans,n-c[x])
print(ans)