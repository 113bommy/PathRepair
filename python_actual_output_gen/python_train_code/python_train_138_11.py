N, x = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
ans = 0
for i in a:
  if x >= i:
    x -= i
    ans += 1
if x == 0:
  print(ans)
else:
  print(min(N - 1, x))