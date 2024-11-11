n = int(input())
ans = n*(n+1)*(n+2)//6
for i in range(n):
  a, b = map(int, input().split())
  if b < a:
    a, b = b, a
  ans -= a*(n-b+1)
print(ans)
