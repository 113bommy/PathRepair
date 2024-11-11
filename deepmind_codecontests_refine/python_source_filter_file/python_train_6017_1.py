import sys
input = sys.stdin.readline
N, M, V, P = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

ng = -1
ok = N - P
#print(a)
def check(x):
  vs = M * V
  p = N
  for i in range(N):
    if a[i] > a[x] + M:
      p = i
      break
  #print(x, vs, p)
  if p < N - P: return False
  #print(x, vs)
  for i in range(N - P + 1, N):
    vs -= M
  #print(x, vs)
  for i in range(N - P):
    vs -= min(max(a[x] + M - a[i], 0), M)

  #print(x, vs)
  return vs <= 0

while ok - ng > 1:
  m = (ok + ng) // 2
  if check(m):
    ok = m
  else: ng = m
print(N - (ng + 1))