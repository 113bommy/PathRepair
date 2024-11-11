n = int(input())

l = len(str(n))
res = 0
base = 1
ab = n
if l > 2:
  base = 9**(l - 2)
  ab = n //(10**(l - 2))
for num in range(1, ab):
  prod = base
  for d in str(num):
    prod *= int(d)
  res = max(res, prod)

if int(str(ab) + '9' * (l - 2)) == n:
  prod = 1
  for d in str(n):
    prod *= int(d)
  res = max(res, prod)
print(res)