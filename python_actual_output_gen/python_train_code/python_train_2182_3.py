rd = lambda: map(int, input().split())
n, m = rd()
a = sorted(([*rd()] + [i + 1] for i in range(m)), key=lambda x: x[1])
r = [0] * n
for x in a:
    r[x[1] - 1] = m + 1
    for i in range(x[1] - 2, x[0] - 2, -1):
        if not r[i]:
            r[i] = x[3]
            x[2] -= 1
            if not x[2]:
                break
    if x[2]:
        print(-1)
        exit()
print(*r)
