t = int(input())
for T in range(t):
  n, k = map(int, input().split())
  a = list(map(int, input().split()))
  res = max(a[0], n - a[-1] + 1)
  last = a[0]
  for x in a[1:]:
    res = max(res, (x + 1 - last) // 2)
    last = x
      
  print(res)
  
