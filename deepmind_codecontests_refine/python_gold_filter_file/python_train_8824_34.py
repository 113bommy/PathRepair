n=int(input())
ans=0
for i in range(1,n+1):
  t=n//i
  ans+=t*(t+1)//2*i
print(ans)

