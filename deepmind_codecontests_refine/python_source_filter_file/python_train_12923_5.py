n, b = map(int, input().split())
ans = 10**30
for p in range(2, 1000000):
  if p * p > b:
    break
  elif b % p == 0:
    t = 0
    while b % p == 0:
      t += 1
      b //= p
    ans = min(ans, sum(n // p**i for i in range(1, 25)) // t)
if b > 1:
    ans = min(ans, sum(n // b**i for i in range(1, 25)))
print(ans)
