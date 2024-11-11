n,m=map(int,input().split())
a,b=map(int,input().split())
for i in range(m-1):
  c,d=map(int,input().split())
  a=max(a,c)
  b=min(b,d)
print(b-a+1)