n, y = map(int, input().split())

for a in range(n):
  for b in range(n-a):
    if 10000*a + 5000*b + 1000*(n-a-b) == y:
      print(a, b, n-a-b)
      exit(0)

print("-1 -1 -1")