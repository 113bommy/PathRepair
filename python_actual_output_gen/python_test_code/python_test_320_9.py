n=int(input())
b=list(map(int,input().split()))
a=list(map(int,input().split()))
ans=0
for i in range(n):
  m=min(b[i],a[i])
  ans+=m
  a[i]-=m
  b[i]-=m
  m=min(b[i+1],a[i])
  ans+=m
  a[i]-=m
  b[i]-=m
print(ans)