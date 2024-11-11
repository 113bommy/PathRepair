n,m,k = map(int,input().split())
for i in range(n):
  for j in range(m):
    black = n*j + m *i - j*i
    if k == black:
      print('Yes')
      exit(0)
print('No')