import sys
input = sys.stdin.readline
R, C, N = map(int, input().split())
a = []

def conv(i, j):
  res = 0
  if i == 0:
    res = j
  elif j == C:
    res = C + i
  elif i == R:
    res = C + R + (C - j)
  elif j == 0: res = 2 * C + R + (R - j)
  else: res = -1
  return res

for i in range(N):
  x, y, u, v = map(int, input().split())
  d, dd = conv(x, y), conv(u, v)
  if d >= 0 and (dd >= 0):
    a.append((d, i))
    a.append((dd, i))
a.sort()
s = []
for _, i in a:
  if len(s) and s[-1] == i: s.pop()
  else: s.append(i)
if len(s): print("NO")
else: print("YES")