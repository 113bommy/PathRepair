n,k = map(int, input().split())
dict = {}
arr = list(map(int, input().split()))
s = set(arr)
x = []
for i in range(0,101):
  x.append(int(-1))
for i in range (0,n):
  x[arr[i]] = int(i)
res = []
for i in range (1,101):
  if x[i] >= 0:
    res.append(x[i]+1)
if len(s) >= k:
  print("YES")
  res = res[:k]
  print(*res)
else:
  print("NO")

  