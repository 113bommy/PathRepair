n,m = map(int,input().split())
if abs(n - m) >= 2:
  print("0")
else:
  if n == m:cou = 2
  else:cou = 1
  while n > 1:
    cou *= n
    cou %= (10 ** 9 + 7)
    n -= 1
  while m > 1:
    cou *= m
    cou %= (10 ** 9 + 7)
    m -= 1
print(cou)