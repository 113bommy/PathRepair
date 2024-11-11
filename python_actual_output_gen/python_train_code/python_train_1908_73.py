n, m, k = map(int, input().split())



for i in range(n):
  for j in range(m):
    a = m*i + n*j - 2*i*j
    if a == k:
      print('Yes')
      exit()
print('No')