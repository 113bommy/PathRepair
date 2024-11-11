s, x1, x2 = map(int, input().split())
t1, t2 = map(int, input().split())
p, d = map(int, input().split())
tr, pe = abs(x1 - x2) * t1, abs(x1 - x2) * t2
if x2 > x1:
    w = 1
else:
    w = -1
if w != d:
    if d == 1:
        tr += (s - p + s - x1) * t1
    else:
        tr += (p + x1) * t1
else:
    if d == w == 1:
        if p < x1:
            tr += (x1 - p) * t1
        else:
            tr += (s - p + s + x1) * t1
    else:
        if p > x1:
            tr += (p - x1) * t1
        else:
            tr += (p + s + s - x1) * t1
print(min(tr, pe))
