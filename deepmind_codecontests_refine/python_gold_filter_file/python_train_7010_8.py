n, m = map(int, input().split())
if n != 0 and m != 0:
  print(max(m, n), n - 1 + m)
elif m == 0:
  print(n, n)
else:
  print("Impossible")