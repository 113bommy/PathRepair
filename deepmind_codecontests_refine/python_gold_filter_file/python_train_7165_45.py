n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
plus = 0
minus = 0
for i in range(n):
  if a[i] > b[i]:
    minus += a[i]-b[i]
  elif a[i] < b[i]:
    plus += (b[i] - a[i])//2
if minus <= plus:
  print('Yes')
else:
  print('No')
