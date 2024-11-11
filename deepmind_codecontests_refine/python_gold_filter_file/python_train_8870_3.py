from math import ceil

n, a, b, k = map(int, input().split())
mon = list(map(int, input().split()))
mon2 = []
p = 0
for x in range(0 ,len(mon), +1):
    if mon[x]%(a+b) > 0 and mon[x]%(a+b) <=a:
        p += 1
    else:
        if mon[x]%(a+b) == 0:
            mon2.append(b)
        else:
            mon2.append(mon[x]%(a+b)-a)
mon2 = sorted(mon2)
for x in mon2:
    if k <= 0:
        break
    if x <= a:
        k -= 1
        p += 1
    else:
        if int(ceil(x/a)) <= k:
            k -= int(ceil(x/a))
            p += 1
print(p)