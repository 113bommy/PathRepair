n, m, k = map(int, input().split())
for i in range(n):
  for j in range(m):
    if (n-j)*i + (m-i)*j == k:
      print('Yes')
      exit()
print('No')