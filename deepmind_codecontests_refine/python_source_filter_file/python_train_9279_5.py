n, x, y = list(map(int, input().split()))

if y > n and n - 1 + (y - n + 1) ** 2 >= x:
  print(' '.join(map(str, [1] * (n - 1) + [y - n + 1])))
else:
  print(-1)