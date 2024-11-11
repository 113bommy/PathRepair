n=int(input())
d,x=map(int,input().split())
for _ in range(n):
  a=int(input())
  x+=d//a+1
print(x)