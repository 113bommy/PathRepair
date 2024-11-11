import bisect
n=int(input())
a=[int(input()) for i in range(n)]
inf=10**6
tmp=[inf]*n
ans=0
for i in range(n-1,-1,-1):
  j= bisect.bisect_right(tmp,a[i])
  tmp[j]=a[i]
for i in range(n):
  if tmp[i]!=inf:
    ans+=1
print(ans)