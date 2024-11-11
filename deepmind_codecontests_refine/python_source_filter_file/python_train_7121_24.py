from functools import reduce
n = int(input())
d = reduce(lambda x, y: (x[0] + y[0], x[1] + y[1]), [(1, 0) if x == '5' else (0, 1) for x in input().split()], (0, 0))
d = (d[0] // 9 * 9, d[1])
d = (d[0], 1 if d[0] == 0 and d[1] > 0 else d[1])
if d[0] + d[1] != 0:
  print("5" * d[0] + "0" * d[1])
else:
  print(-1)