n, k = map(int, input().split())
arr = list(map(int, input().split()))
l = []
yes = 0
points = 0
for b in range(n):
  l.append(0)

for i in range(k):
  for a in range(1,n+1):
    if arr[i] == a:
      l[a-1] = l[a-1]+1
      break
for d in range(n):
    for c in range(n):
        if l[c]>=1:
          yes = yes + 1
        else:
          break
    if yes == n:
      points = points + 1
      yes = yes - n
      for e in range(n):
        l[e] = l[e]-1
    else:
      break
print(points)
    