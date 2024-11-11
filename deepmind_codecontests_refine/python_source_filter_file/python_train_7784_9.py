n, m = map(int, input().split())
a, b = n, 1
V = [False for d in range(1, m + 2)]
for i in range(m):
    d = min(a - b, n - (a - b))
    if 2 * d == n or V[d]:
        a -= 1
    print(a, b)
    d = min(a - b, n - (a - b))
    V[d] = True
    a -= 1
    b += 1
