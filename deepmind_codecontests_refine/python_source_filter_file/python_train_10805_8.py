n = int(input())
raw = []
for _ in range(n):
  raw.append(list(map(lambda x: int(x)-1, input().split())))
cnt = [0 for _ in range(n)]
now = []
for i in range(n):
  j = raw[i][cnt[i]]
  if raw[j][cnt[j]] == i and i < j:
    now.append([i,j])
ans = 0
while now:
  print(now)
  last = now
  now = []
  for x in last:
    i,j = x[0],x[1]
    cnt[i] += 1
    cnt[j] += 1
    if cnt[i] < n-1:
      k = raw[i][cnt[i]]
      if raw[k][cnt[k]] == i:
        now.append([i,k])
    if cnt[j] < n-1:
      k = raw[j][cnt[j]]
      if raw[k][cnt[k]] == j:
        now.append([j,k])
  ans += 1
if all( cnt[i] == n-1 for i in range(n) ):
  print(ans)
else:
  print(-1)