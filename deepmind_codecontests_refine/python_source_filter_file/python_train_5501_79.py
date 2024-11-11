n,m,k = map(int,input().split())
for i in range(n+1):
  for j in range(m+1):
    black = n*j + m *i - j*i
    if k == black:
      print('Yes')
      exit(0)
print('No')
