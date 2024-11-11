L, R = tuple(list(map(int, input().split(' '))))
L = L - 1
ans = 0
oidx = 0
eidx = 0
csum = 0
cnt = 1
mod = int(1e9 + 7)
i = 1
while csum <= R:
    l = max([csum, L])
    csum += cnt
    r = min([R, csum])
    if i % 2 == 1: oidx += cnt;
    else: eidx += cnt;
    cnt *= 2
    bv = 1 if i % 2 == 1 else 2
    bv += 2 * (l - (eidx if i % 2 == 1 else oidx))
    i += 1
    if r <= l: continue;
    ev = bv + (r - l - 1) * 2
    ans += (bv + ev) * (r - l) // 2 % mod
print(ans % mod)
