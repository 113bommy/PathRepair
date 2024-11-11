n,m=map(int,input().split())
a,b=0,n-1
for i in range(m):
  l,r=map(int,input().split())
  a=max(a,l-1);b=min(b,r-1)
print(max(0,b-a+1))