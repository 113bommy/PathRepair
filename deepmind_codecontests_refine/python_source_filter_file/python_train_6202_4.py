s, x1, x2 = map(int, input().split())

t1, t2 = map(int, input().split())

p, d = map(int, input().split())

if x2 < x1:
    x1 = (s - x1)
    x2 = (s - x2)
    p = (s - p)
    d = -d

vt = 1.0 / t1
vi = 1.0 / t2
xt0 = 0.0

if d == -1:
    xt0 = -p
elif p <= x1:
    xt0 = p
else:
    xt0 = -(s - p) - s

def solve(vt, xt0, vi, x1, x2):
    t1 = (x1 - xt0) / (vt - vi)
    t2 = (x2 - vi*t1 - x1) / vt
    t3 = (x1 - xt0) / (vt + vi)
    t4 = (x2 + vi*t3 - x1) / vt
    return min((x2-x1) / vi, min(t1 + t2, t3 + t4))

if t2 <= t1:
    print("%.1f" % ((x2 - x1) / vi))
else:
    print("%.1f" % solve(vt, xt0, vi, x1, x2))
