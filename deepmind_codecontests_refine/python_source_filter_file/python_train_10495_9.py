import sys
#sys.setrecursionlimit(10 ** 7)

dct = {"#": 0, ".": 1, "-": 2}


def f(c):
    return dct[c]


h, w = map(int, input().split())
s = [[2] * (w + 2)]
for _ in range(h):
    s.append([2] + list(map(f, input())) + [2])
s.append([2] * (w + 2))

d = [(-1, 0), (1, 0), (0, -1), (0, 1)]


def dfs(col, hh, ww):
    if s[hh][ww] != col:
        return

    cnt[col] += 1
    s[hh][ww] = 2

    for dh, dw in d:
        nh = hh + dh
        nw = ww + dw
        dfs(1-col, nh, nw)


ans = 0
for hi in range(1, h + 1):
    for wi in range(1, w + 1):
        cnt = [0, 0]
        if s[hi][wi] != 2:
            dfs(s[hi][wi], hi, wi)
        ans += cnt[0] * cnt[1]

print(ans)
