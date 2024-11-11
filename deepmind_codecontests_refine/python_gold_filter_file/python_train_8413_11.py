q = int(input())
for _ in range(q):
    R = list(map(int, input().split()))
    a, b = min(R), max(R)
    if b - a <= 1:
        res = 2 * (a-1)

    else:
        c = int((a*b)**0.5)
        if c ** 2 == a * b:
            c -= 1
        if c * (c+1) < a * b:
            res = 2 * (c-1) + 1
        else:
            res = 2 * (c-1)
    print(res)