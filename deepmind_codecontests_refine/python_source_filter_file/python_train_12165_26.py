n, k = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]

for i in range(n):
  k -= a[i][1]
  if k <= 0:
    print(a[i][0])
    break