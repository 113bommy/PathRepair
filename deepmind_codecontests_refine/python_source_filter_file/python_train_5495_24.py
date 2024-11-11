k,n = map(int,input().split())
a=list(map(int,input().split()))
ans=(a[0]-a[-1])+k
for i in range(n-1):
  ans=max(a[i+1]-a[i],ans)
print(ans)