h, m, s, t1, t2 = tuple(map(int, input().split()))

t2 = (t2 % 12) * 5
t1 = (t1 % 12) * 5

s = float(s)
m = float(m + s / 60)
h = float((h % 12) * 5 + m / 12)

def dt(u, v):
    if v < u:
        return (60 - u) + v
    return v - u

def check(t1, t2, h, m, s):
    d = dt(t1, t2)
    return d < dt(t1, h) and d < dt(t1, m) and d < dt(t1, s)

r = check(t1, t2, h, m, s) or check(t2, t1, h, m, s)
print("YES" if r else "NO")
