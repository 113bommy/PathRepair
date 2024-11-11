import sys


def solve(a, b, c, d):
    """ Lv.i の中央の■を、上下(a,c)に迂回する """
    for i in range(3, 0, -1):
        # ここに到達している時点で、Lv.i 盤面の同じ横ならびに位置することは保証されている
        d3i = d3[i - 1]
        da, ma = divmod(a, d3i)
        dc, mc = divmod(c, d3i)
        if da != dc:
            return abs(a - c) + abs(b - d)
        if da != 1:
            a, c = ma, mc
            continue
        db, mb = divmod(b, d3i)
        dd, md = divmod(d, d3i)
        if (abs(db - dd) < 2):
            a, c = ma, mc
            continue
        return min(ma + mc + 2, 2 * d3i - (ma + mc)) + abs(b - d)
    return abs(a - c) + abs(b - d)


d3 = [pow(3, i) for i in range(31)] + [0]

q = int(input())
buf = []
for line in sys.stdin:
    a, b, c, d = map(int, line.split())
    a -= 1
    b -= 1
    c -= 1
    d -= 1
    ans = max(solve(a, b, c, d), solve(b, a, d, c))
    buf.append(ans)
print('\n'.join(map(str, buf)))
