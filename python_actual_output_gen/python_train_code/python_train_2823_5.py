n, r = list(map(int, input().split()))
a = list(map(int, input().split()))
a.insert(0, 0)
pos = 1
ans = 0
last = 0
while(True):
  if pos >= n:
    break
  prelast = last
  for i in range(max(0, pos - r + 1), min(pos + r, n + 1)):
    if a[i] == 1:
      pos = i + r
      last = i
  if prelast == last:
    ans = -1
    break
  else:
    ans += 1
print(ans)