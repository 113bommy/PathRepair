cnt = [6, 2, 5, 5, 5, 4, 5, 6, 4, 7, 6]

def f(n):
  ans = 0
  while n != 0:
    ans += cnt[n % 10]
    n //= 10
  return ans

a, b = map(int, input().split())
ans = 0
for i in range(a, b + 1):
  ans += f(i)
print(ans)