N = int(input())
P = [int(x) for x in input().split()]
L = [0] * (N + 2)
R = [N + 1] * (N + 2)
I = list(range(N + 1))
for i in range(N):
  I[P[i]] = i
ans = 0
ST = [0] * (N + 2)
def cnt(i):
  ret = 0
  while i:
    ret += ST[i]
    i -= i & (-i)
  return ret
def update(i):
  while i <= N + 1:
    ST[i] += 1
    i += i & (-i)
def ls(idx):
  b = cnt(idx)
  if b == 0:
    return 0
  s = 0
  t = idx
  while t - s > 1:
    m = (s + t) // 2
    if cnt(m) < b:
      s = m
    else:
      t = m
  return t
def rs(idx):
  b = cnt(idx)
  s = idx
  t = N + 1
  while t - s > 1:
    m = (s + t) // 2
    if cnt(m) > b:
      t = m
    else:
      s = m
  return t
for i in range(N, 0, -1):
  index = I[i]
  idx = index + 1
  L[idx] = ls(idx)
  R[idx] = rs(idx)
  L[R[idx]] = idx
  R[L[idx]] = idx
  update(idx)
  ans += i * ((idx - L[idx]) * (R[R[idx]] - R[idx]) + (L[idx] - L[L[idx]]) * (R[idx] - idx))
print(ans)