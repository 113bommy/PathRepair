a,b,m=map(int,input().split())
al=list(map(int,input().split()))
bl=list(map(int,input().split()))
x=min(al)+min(bl)
for i in range(m):
  x,y,c=map(int,input().split())
  t=al[x-1]+bl[y-1]-c
  x=min(x,t)
print(x)