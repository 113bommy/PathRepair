n, m = map(int, input().split())
d = {i+1 : [] for i in range(n)}
for _ in range(m):
  a, b = map(int, input().split())
  d[a].append(b)
  d[b].append(a)
ans = 0
def go(c, rem):
  global ans
  if not len(rem):
    ans += 1
    return
  for cand in d[c]:
    if cand in rem:
      i = rem.index(cand)
      go(cand, rem[:i] + rem[i+1:])
go(1, list(range(2, n+1)))
print(ans)
