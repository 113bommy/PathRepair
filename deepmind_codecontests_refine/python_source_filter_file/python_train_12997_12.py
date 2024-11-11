from heapq import heappush, heappop
n=int(input())
a=list(map(int,input().split()))
l=[]
for v in a[:n]:
  heappush(l,v)
suml=[sum(a[:n])]
for i in range(n):
  suml.append(suml[i]+a[n+i])
  heappush(l,a[n+i])
  suml[i+1]-=heappop(l)
r=[]
for v in a[2*n:]:
  heappush(r,(10**10-v,v))
sumr=[sum(a[2*n:])]
for i in range(n):
  sumr.append(sumr[i]+a[2*n-i-1])
  heappush(r,(10**10-a[2*n-i-1],a[2*n-i-1]))
  _,t=heappop(r)
  sumr[i+1]-=t
ans=-10**10
for i in range(n+1):
  ans=max(ans,suml[i]-sumr[n-i])
print(ans)