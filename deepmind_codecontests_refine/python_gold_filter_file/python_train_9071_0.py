calc = [0] * 80
l, r = [int(x) for x in input().split(' ')]
pl = 0
pr = 0
deg = 1
p = 0
calc[0] = 1
calc[1] = 2
while deg <= 16000000000000000000:
    if deg & l:
        pl = p
    if deg & r:
        pr = p
    if p > 1:
        calc[p] = calc[p-2] + (1 << (p - 2)) * 2
    deg *= 2
    p += 1
if pl == pr:
    killL = l - (1 << pl)
    killR = (1 << (pr + 1)) - r - 1
    ans = (calc[pl] + killL * 2 + calc[pl+2] - 2 - killR * 2) * ((1 << pl) - killL - killR) // 2
    print(ans % 1000000007)
    exit(0)
killL = l - (1 << pl)
killR = (1 << (pr + 1)) - r - 1
ans = (calc[pl] + killL * 2 + calc[pl+2] - 2) * ((1 << pl) - killL) // 2
ans += (calc[pr] - killR * 2 + calc[pr+2] - 2) * ((1 << pr) - killR) // 2
for t in range(pl+1, pr):
    ans += (calc[t] + calc[t+2] - 2) * (1 << t) // 2
print(ans % 1000000007)
