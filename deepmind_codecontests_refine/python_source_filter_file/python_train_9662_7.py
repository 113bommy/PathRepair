n=int(input())
x=list(map(int,input().split()))
ans=0
for i in range(n-1):
  ans+=max(0,x[i+1]-x[i])
print(ans)