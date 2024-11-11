n=int(input())
ans=0
for i in range(1,n+1):
  we=n//i
  ans+=we*(we+1)*i//2
print(ans)