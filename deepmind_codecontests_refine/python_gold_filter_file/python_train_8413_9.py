q = int(input())
ab = [list(map(int, input().split())) for _ in range(q)]

for a, b in ab:
    if a == b:
        print(2 * a - 2)
        continue

    l = 1
    r = 10 ** 10
    while r - l > 1:
        m = (l + r) // 2
        mx = (m + 1) // 2 * (m + 1 - (m + 1) // 2)
        if mx < a * b:
            l = m
        else:
            r = m

    print(l - 1)
