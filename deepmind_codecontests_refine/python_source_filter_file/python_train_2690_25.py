h, w = map(int, input().split())
c = [0]*10
for i in range(10):
  c[i] = [int(x) for x in input().split()]


for i in range(10):
  for j in range(10):
    for k in range(10):
      c[i][j] = min([c[i][j], c[i][k]+c[k][j]])

ans = 0
for i in range(h):
  a = [int(x) for x in input().split()]
  for j in range(w):
    if a[j] == -1:
      continue
    else:
      ans += c[a[j]][1]

print(ans)


