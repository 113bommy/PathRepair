n, m = [int(x.strip()) for x in input().split()]

u = [[int(x.strip()) for x in input().split()] for _ in range(n)]
u = [(max(x[0] - x[1], 1), min(x[0] + x[1], m)) for x in u]
u = sorted(u)

d = [2 ** 60] * (m+11)
d[0] = 0

for s, e in u:
    next_d = [2 ** 60] * (m+11)
    minv = min(d[max(0, s-1):])

    expand = max((0, m - e, s - 1))
    for j in range(expand):
        st, ed = max(0, s - j - 1), min(m, e + j)
        minv = min(minv, d[st])
        next_d[ed] = min(next_d[ed], minv + j)

    minv = next_d[-1]
    for j in range(m, 0, -1):
        minv = min(minv, next_d[j], d[j])
        d[j] = minv

print(d[m])