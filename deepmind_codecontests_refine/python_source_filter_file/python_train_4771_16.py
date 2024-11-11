n = int(input())
res = n
for i in range(n):
  t = i
  c = 0
  while t > 0:
    c += t % 9
    t //= 9
  t = n - i
  while t > 0:
    c += t % 6
    t //= 6
  if res > c:
    res = c
print(res)