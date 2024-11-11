n=int(input())
ans=0
for i in range(1,n+1):
  num=n//i
  ans+=((num*(num+1))//2)*i
print(ans)
