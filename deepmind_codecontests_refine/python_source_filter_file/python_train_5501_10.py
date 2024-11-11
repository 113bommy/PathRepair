n, m, k = map(int, input().split())
for i in range(n+1):
  for j in range(m+1):
    if (n-j)*i + (m-i)*j == k:
      print('Yes')
      exit()
print('No')