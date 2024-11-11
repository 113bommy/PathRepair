n = int(input())
dh = {}
dv = {}

for i in range(n * n):
  h, v = map(int, input().split())
  if h not in dv and v not in dh:
    print(i + 1, end = ' ')
    dh[h] = 1
    dv[v] = 1
