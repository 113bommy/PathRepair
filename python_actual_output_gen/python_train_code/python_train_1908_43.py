n, m, k = map(int, input().split())
for i in range(n):
  for j in range(m):
    if i * m + (n - 2 * i) * j == k:
      print("Yes")
      exit()
print("No")