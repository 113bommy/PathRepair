import io, os
input = io.StringIO(os.read(0, os.fstat(0).st_size).decode()).readline

ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())

n = ii()
s = input().strip()
f = [[0] * 26 for _ in range(n + 1)]
for i in range(n):
    f[i] = f[i - 1][:]
    f[i][ord(s[i]) - 97] += 1
m = ii()
out = []
for _ in range(m):
    t = input().strip()
    c = [0] * 26
    for x in t:
        c[ord(x) - 97] += 1
    lo, hi = 0, n - 1
    while lo < hi:
        mid = (lo + hi) // 2
        ok = sum(x >= y for x, y in zip(f[mid], c)) == 26
        if ok:
            hi = mid
        else:
            lo = mid + 1
    out.append(lo + 1)
print(*out, sep='\n')