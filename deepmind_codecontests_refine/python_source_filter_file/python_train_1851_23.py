n,d = map(int,input().split())
res = 0
for _ in range(n):
  x,y = map(int,input().split())
  if x*x+y*y>=d*d:
    res+=1
print(res)