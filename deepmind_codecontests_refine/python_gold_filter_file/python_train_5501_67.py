n, m, k = map(int, input().split())

for i in range(n+1):
  for j in range(m+1):
    a = m*i + n*j - 2*i*j
    if a == k:
      print('Yes')
      exit()
print('No')