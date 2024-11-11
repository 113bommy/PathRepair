x,y = map(int,input().split())
n = 0
mod = 10**9+7
ans = 0
if not (x+y)%3:
  n = (x+y)//3
  x-=n
  y-=n
  if not x<0 or y<0:
    ans = 1
    for i in range(x):
      ans = ans*(n-i)*pow(i+1,mod-2,mod)%mod
print(ans)