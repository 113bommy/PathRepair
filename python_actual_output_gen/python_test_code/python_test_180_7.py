n, x, m = map(int, input().split())

a = []
check = [-1] * m
i = 0
while check[x] == -1:
  a.append(x)
  check[x] = i
  x = x * x % m
  i += 1
if n <= i:
  print(sum(a[:n]))
else:
  print(
    sum(a[:check[x]])
    + (n - check[x]) // (i - check[x]) * sum(a[check[x]:])
    + sum(a[check[x] : check[x] + (n - check[x]) // (i - check[x])]))