n = [int(x) for x in input().strip().split()]
m = [int(y) for y in input().strip().split()]
if n[1] == (sum(m) + n[0] - 1):
  print('YES')
else:
  print('NO')