from itertools import combinations

EPS = 1e-8

N, K, *XYC = map(int, open(0).read().split())
PC = [(complex(x, y), c) for x, y, c in zip(*[iter(XYC)] * 3)]


def intersection(A, r, B, s):
    D = B - A
    d = abs(D)

    cos_t = (d * d + r * r - s * s) / (2 * d * r)
    sin_t = max(1 - cos_t * cos_t, 0.0) ** 0.5

    R = r * complex(cos_t, sin_t)
    D /= d

    return (
        A + D * R,
        A + D * R.conjugate(),
    )


def is_ok(T):
    A = [p for p, _ in PC]
    for (p1, c1), (p2, c2) in combinations(PC, 2):
        A += intersection(p1, T / c1, p2, T / c2)

    for a in A:
        cnt = 0
        for p, c in PC:
            if c * abs(a - p) <= T + EPS:
                cnt += 1
        if K <= cnt:
            return True
    return False


ng, ok = 0, 10000000
for _ in range(100):
    md = (ng + ok) / 2
    if is_ok(md):
        ok = md
    else:
        ng = md

print(ok)