import sys
input = sys.stdin.readline
N = int(input())
a = []
l = []
r = []
lr = []
u = []
d = []
ud = []
for _ in range(N):
  x, y, w = input().split()
  x, y = map(int, (x, y))
  a.append((x, y, w))

  if w == "L":
    l.append(x)
    ud.append(y)
  if w == "R":
    r.append(x)
    ud.append(y)
  if w == "U":
    u.append(y)
    lr.append(x)
  if w == "D":
    d.append(y)
    lr.append(x)

l.sort()
r.sort()
lr.sort()
u.sort()
d.sort()
ud.sort()

t = [0]
if len(l):
  if len(r): t.append((l[-1] - r[-1]) / 2)
  if len(lr):
    t.append(l[-1] - lr[-1])
    t.append(l[0] - lr[0])
if len(r):
  if len(l): t.append((r[0] - l[0]) / 2)
  if len(lr):
    t.append(r[0] - lr[0])
    t.append(lr[-1] - r[-1])
if len(d):
  if len(u): t.append((d[-1] - u[-1]) / 2)
  if len(ud):
    t.append(d[-1] - ud[-1])
    t.append(d[0] - ud[0])
if len(u):
  if len(d): t.append((u[0] - d[0]) / 2)
  if len(ud):
    t.append(u[0] - ud[0])
    t.append(ud[-1] - u[-1])

t = sorted(set(t), reverse = True)
while t[-1] < 0: t.pop()

def solve(tt):
  ll = float("inf")
  rr = -float("inf")
  uu = -float("inf")
  dd = float("inf")
  for x, y, w in a:
    xx = x
    yy = y
    if w == "L": xx -= tt
    if w == "R": xx += tt
    if w == "U": yy += tt
    if w == "D": yy -= tt
    ll = min(ll, xx)
    rr = max(rr, xx)
    uu = max(uu, yy)
    dd = min(dd, yy)
  return (rr - ll) * (uu - dd)

res = float("inf")
for tt in t: res = min(res, solve(tt))
print(res)