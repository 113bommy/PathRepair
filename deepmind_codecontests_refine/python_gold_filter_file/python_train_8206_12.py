n=int(input())
a=list(map(int,input().split()))
for i in range(n-1):
  a[i+1]+=a[i]
m=a[-1]
ans=10**18
for i in range(n-1):
  ans=min(ans,abs(m-2*a[i]))
print(ans)