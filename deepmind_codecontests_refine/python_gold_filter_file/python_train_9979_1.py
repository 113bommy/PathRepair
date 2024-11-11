N = int(input())
MOD = 10 ** 9 + 7
x = 1
for i in range(2, N + 1):
  x *= i

count = 1
ans = 1
for i in range(2, N + 1):
  if x % i != 0:
    continue
  count = 1
  while x % i == 0:
    x //= i
    count += 1
  ans *= count
print(ans % MOD)