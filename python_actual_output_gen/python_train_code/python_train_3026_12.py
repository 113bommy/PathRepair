n = int(input())
m = n**2 + 1
t = n//2

for i in range(t):
  x = t*n + 1
  for j in range(x, x + t):
    print(j, m - j, end=' ')
  print()
    