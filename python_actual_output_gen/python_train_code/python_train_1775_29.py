t = int(input())
for _ in range(t):
  n,k = map(int,input().split())
  a = list(map(int,input().split()))
  ans = 0
  for i in range(n):
    k -= a[i]*i
    if k >= 0:
      ans += a[i]
    else:
      ans += max(0,(a[i]*i-k)//i)
  print(ans)