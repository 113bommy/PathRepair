n, m = map(int, input().split())
if n != 0 and m != 0:
  print(m, n - 1 + m)
elif m == 0:
  print(n, n)
else:
  print("Impossible")