n, m = map(int,input().split())
a = [list(map(int,input().split())) for i in range(n)]
a.sort()
ans = 0
i = 0
while m > 0:
  if a[i][1] > 0:
    a[i][1] -= 1
    ans += a[i][0]
    m -= 1
  else:
    i += 1
print(ans)
