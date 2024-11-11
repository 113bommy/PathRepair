n=int(input())
a=list(map(int,input().split()))
a=a+[10**18]
ans=a[0]
for i in range(n-1):
  ans+=min(a[i],a[i+1])
print(ans)
