n=int(input())
t=list(map(int,input().split()))
m=int(input())
for i in range(m):
  p,x=map(int,input().split())
  y=t[p-1]
  t[p-1]=x:
  print(sum(t))
  t[p-1]=y