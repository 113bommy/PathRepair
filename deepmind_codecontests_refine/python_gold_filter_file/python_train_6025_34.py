n, l = map(int, input().split())
a = list(map(int, input().split()))
ma = 0
midx = 0
for i in range(n - 1):
  if ma < a[i] + a[i + 1]:
    midx = i
    ma = a[i] + a[i + 1]
if l > ma:
  print('Impossible')
else:
  print('Possible')
  for i in range(midx):
    print(i + 1)
  for i in range(n - 1, midx, -1):
    print(i)
  