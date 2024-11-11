def f():
    a, b, c, ra = [int(s) for s in input().split()]
    if a > b:
        a, b = b, a
    if a == b:
        return 0
    if ra == 0:
        return b - a
    l = c - ra
    r = c + ra
    if l <= a:
        if r <= a:
            return b - a
        if r < b:
            return b - r
        else:
            return 0
    elif l < b:
        if r <= b:
            return b-r + l-a
        else:
            return l - a
    else:
        return b-a

t = int(input())
for i in range(t):
    print(f())