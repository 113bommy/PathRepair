n=int(input())
ans=0
for i in range(1,n+1):
  s=n//i
  ans+=i*(s*(s+1))//2
print(ans)