d=[105,3*5*9,3*5*11,3*5*5*5,27*7]
n=int(input())
ans=0
for i in range(len(d)):
  if d[i]<=n:
    ans+=1
print(ans)