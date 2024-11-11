f = lambda: list(map(int, input().split()))
m, t, r = f()
p, s = [], 0
for w in f():
    p = [q for q in p if q > w]
    d = r - len(p)
    p += [w + t - i for i in range(d)]
    s += d
print(s if t > r else -1)