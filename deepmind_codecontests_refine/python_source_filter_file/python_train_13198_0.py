def calc(a, b, c, d):
    if abs(c - a) < abs(d - b): a, b, c, d = b, a, d, c
    if c < a: a, b, c, d = c, d, a, b
    
    s = 3 ** 29
    while s:
        bb = b // s
        dd = d // s
        if bb != dd: return c - a + abs(d - b)
        if bb == 1 and c // s - a // s >= 2:
            l = bb * s - 1
            r = (bb + 1) * s
            return c - a + min(b + d - 2 * l, 2 * r - b - d)
        s //= 3
    return c - a + abs(d - b)

Q = int(input())
for _ in range(Q):
    a, b, c, d = map(int, input().split())
    print(calc(a-1, b-1, c-1, d-1))