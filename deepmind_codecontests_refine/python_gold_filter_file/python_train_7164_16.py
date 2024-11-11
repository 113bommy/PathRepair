n, m, q = map(int, input().split())

dia = [[0]*(n+1) for i in range(n+1)]
for i in range(m):
  l, r = map(int, input().split())
  dia[l][r] += 1
  
lst = [[0]*(n+1) for i in range(n+1)]
for i in range(1, n+1):
  for j in range(i, n+1):
    lst[i][j] = lst[i][j-1] + dia[i][j]
    
for i in range(q):
  l, r = map(int, input().split())
  count = 0
  for j in range(l, r+1):
    count += lst[j][r]
  print(count)