a,b=map(int,input().split())
ans=0
while b>a:
  a*=2
  ans+=1
print(ans)