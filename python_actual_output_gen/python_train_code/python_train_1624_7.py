n=int(input())
a=0
ans=0
for i in range(n):
  x,y=map(int,input().split())
  if a<x:
    ans=x+y-1
    a=x
print(ans)