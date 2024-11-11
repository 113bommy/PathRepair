c = '0123456789'
F = {c[a] + c[b]: (c[10 - a + b], 1) if a > b else (c[10 - a], 2) for a in range(1, 10) for b in range(10)}
for b in range(1, 10): F['0' + c[b]] = ('0', 1)
F['00'] = ('0', 0)

def f(x):
    global F
    if x in F: return F[x]
    a, b, y, s = int(x[0]), int(x[1]), x[2: ], 0
    for i in range(b, a, -1):
        y, d = f(c[i] + y)
        s += d
    for i in range(a, -1, -1):
        y, d = f(x[0] + y)
        s += d
    F[x] = ('9' + y, s)
    return F[x]

print(f('0' + input())[1]) 