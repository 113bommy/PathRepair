n,a,b=map(int,input().split())

ans=0
for i in range(1,n+1):
  s=str(i)
  s=sum(list(map(int,s)))
  if a<=s<=b:
    ans+=i
print(ans)
