vp, vd, t, f, c = [int(input()) for i in range(5)]
if vp >= vd:
    exit(print(0))
cur = (vp * vp * t * vd) / (vd - vp)
ans = 0
while c > cur:
    ans += 1
    cur += vp * (2 * cur + f * vd) / (vd - vp)
print(ans)