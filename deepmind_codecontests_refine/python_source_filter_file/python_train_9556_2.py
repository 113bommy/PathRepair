n, x, d = map(int, input().split())

if d == 0:
  if x == 0:
    print(1)
    exit
  else:
    print(n + 1)
    exit
if d < 0:
  y = x
  x = x + d * (n - 1)
  d = -d
else:
  y = x + d * (n - 1)
  
U = {}
ans = 0
has0 = 0
for k in range(1, n + 1):
  r = (x * k) % d
  s = k * d * (k - 1) // 2
  v1 = k * x + s
  v2 = k * y - s
  if r in U:
    u = U[r]
    if v1 > u[1] or v2 < u[0]:
      ans += (u[1] - u[0]) // d + 1
    else:
      v1 = min(v1, U[r][0])
      v2 = max(v2, U[r][1])
  U[r] = (v1, v2)
  if r == 0 and v1 <= 0 and v2 >= 0:
    has0 = 1
#  print(ans, k, v1, v2, U)

for r, u in U.items():
  ans += (u[1] - u[0]) // d + 1

if not has0: ans += 1
  
print(ans)