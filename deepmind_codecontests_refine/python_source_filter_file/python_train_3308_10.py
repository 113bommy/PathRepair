import sys

n, *inp = map(int, sys.stdin.buffer.read().split())
vvv = [0] + inp[0:n * 2:2]
www = [0] + inp[1:n * 2:2]

weight_limit = 10 ** 5
precalc_limit = min(1 << 11, n + 1)
precalc = [[0] * (weight_limit + 1)]

for u in range(1, precalc_limit):
    v = vvv[u]
    w = www[u]
    dp = precalc[u >> 1][:]
    for x in range(weight_limit, w - 1, -1):
        nv = dp[x - w] + v
        if dp[x] < nv:
            dp[x] = nv
    precalc.append(dp)

buf = []
mp = iter(inp[n * 2 + 1:])
for u, l in zip(mp, mp):
    if u < precalc_limit:
        buf.append(precalc[u][l])
        continue
    dp_w = [0]
    dp_v = [0]
    while u >= precalc_limit:
        v = vvv[u]
        w = www[u]
        for i in range(len(dp_w)):
            nw = dp_w[i] + w
            if nw > l:
                continue
            nv = dp_v[i] + v
            dp_w.append(nw)
            dp_v.append(nv)
        u >>= 1
    ans = 0
    for w, v in zip(dp_w, dp_v):
        nv = v + precalc[u][l - w]
        if ans < nv:
            ans = nv
    buf.append(ans)

print('\n'.join(map(str, buf)))
