n, k, d = map(int, input().split())
ans = [[0 for j in range(n)] for i in range(d)]
if any(1 for i in range(d) if k**(i + 1) >= n):
  for i in range(n):
    N = i
    for j in range(d):
      ans[j][i] = 1 + N % k
      N //= k
  for i in range(d):
    print(' '.join(map(str, ans[i])))
else:
  print(-1)
