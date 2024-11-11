EPS = 1e-10
N, K = map(int, input().split())
pts = []
Cs = []
for _ in range(N):
    x, y, c = map(int, input().split())
    pts.append(x + y * 1j)
    Cs.append(c)

Rs = [0] * N


def cands():
    for i in range(N):
        yield pts[i]
        for j in range(i + 1, N):
            pt = pts[j] - pts[i]
            ab = -2 * pt
            l = ab * ab.conjugate()
            c = pt * pt.conjugate() + Rs[i] - Rs[j]
            d = Rs[i] - c * c / l
            if d.real < 0:
                continue
            m = (d / l) ** 0.5
            off = m * (ab.imag - ab.real * 1j)
            yield -ab * c / l + off + pts[i]
            yield -ab * c / l - off + pts[i]


def ok(secs):
    for i in range(N):
        Rs[i] = secs * secs / Cs[i] / Cs[i]
    for cand in cands():
        count = 0
        for pt, r in zip(pts, Rs):
            xy = pt - cand
            if (xy * xy.conjugate()).real < r + EPS:
                count += 1
                if count == K:
                    return True
    return False


lo = 0
hi = 1e10
for _ in range(100):
    mid = (lo + hi) / 2
    if ok(mid):
        hi = mid
    else:
        lo = mid
print(hi)
