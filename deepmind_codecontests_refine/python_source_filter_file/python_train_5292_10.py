n=int(input())
t=0
m=1e18
f=0
for i in range(n):
  a,b=map(int,input().split())
  t+=a
  if a>=b:m=min(m,b)
  if a!=b:f=1
if f:
  print(t-m)
else:
  print(0)