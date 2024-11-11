n,m = map(int, input().split())
if n == m:
  print(0)
elif m * 2 > n:
  k = m - n//2
  if n % 2 != 0:
    k -= 1
  print(n//2-k)
else:
  print(m)