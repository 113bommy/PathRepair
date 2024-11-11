def read(): return list(map(int, input().split()))

[t] = read()
for q in range(t):
    read()
    a = read()
    read()
    b = read()
    h = [0, 0]
    g = [0, 0]
    for x in a:
        h[x % 2] += 1
    for x in b:
        g[x % 2] += 1
    print(h[0] * g[0] + h[1] % g[1])