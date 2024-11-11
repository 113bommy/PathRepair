n,d=map(int,input().split())
x=[]
for _ in range(d):
  x+=[list(map(int,input().split()))]
ans=0
for i in range(d):
  for j in range(i+1,d):
    l=0
    for k in range(n):
      l+=(x[i][k]-x[j][k])**2
    l=l**0.5
    if l.is_integer():
      ans+=1
print(ans)