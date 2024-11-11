n = int(input())
a = list(map(int,input().split()))
a.sort(reverse=True)
cnt = [0]*n
ans = 0
for i in range(100000):
  j = i%n
  if a[j]<n:
    continue
  x = a[j]//n
  y = a[j]%n
  a[j] = y
  ans += x
  for k in range(n):
    if j == k:
      continue
    a[k] += y
print(ans)
