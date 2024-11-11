m=int(input())
n=0
ans=0
for i in range(m):
  x,y=map(int,input().split())
  n+=y
  ans+=x*y
n-=1
n+=ans//9
print(n)