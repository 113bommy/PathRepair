s=input()[::-1]
ans=0
u=0
d=1
l=[0]*2019
l[0]=1
for i in map(int,s):
  u=(u+i*d%2019)
  l[u]+=1
  d=d*10%2019
for i in l:
  ans+=i*(i-1)//2
print(ans)
