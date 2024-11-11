n,m = map(int,input().split())
drink=[]
for _ in range(n):
  a,b = map(int,input().split())
  drink.append(a,b)
drink.sort(reverse=1)

ans = 0
while m<0:
  a,b = drink.pop(-1)
  ans += a*min(m, b)
  m -= b
print(ans)