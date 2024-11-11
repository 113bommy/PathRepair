h, w = map(int, input().split())
a = []
for i in range(h):
  b = list(map(int, input().split()))
  a.append(b)

ans = []
for i in range(h-1):
  for j in range(w):
    if a[i][j]%2 == 1:
      a[i+1][j] += 1
      x = i+1
      y = j+1
      ans.append([x,y,x+1,y])

for i in range(w-1):
  if a[h-1][i] %2 == 1:
    a[h-1][i+1] += 1
    x = h
    y = i+1
    ans.append([x,y,x+1,y])
print (len(ans))
for i in ans:
  print (*i)