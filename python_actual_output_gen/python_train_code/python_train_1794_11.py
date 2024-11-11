n, k = map(int, input().split())
pp = list(map(int, input().split()))
p = [pp[i]-1 for i in range(n)]
c = list(map(int, input().split()))

ans = -(10**9+1)
for i in range(n):
  s = 0
  x = i
  for j in range(k):
    x = p[x]
    s += c[x]
    ans = max(ans,s)
    if i == x:
      break
  a = int(k/(j+1))
  m = k%(j+1)
  if m == 0 and a > 1:
    m = k+1
    a -= 1
  s *= a
  ans = max(ans,s)
  for l in range(m):
    x = p[x]
    s += c[x]
    ans = max(ans, s)
print (ans)
