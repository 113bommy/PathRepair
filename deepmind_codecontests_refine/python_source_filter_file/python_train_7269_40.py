n, y = map(int, input().split())
for i in range(n+1):
  for g in range(n-i):
    s = n-i-g
    if 10000*i + 5000*g + 1000*s == y:
      print(i, g, s)
      exit()
print('-1 -1 -1')