from collections import Counter
n = int(input())
smin = []
smax = []
tot = 0
bite = - 1
for i in range(n):
    ss = list(map(int, input().split()[1:]))
    if ss == sorted(ss, reverse=True):
        smin += [min(ss)]
        smax += [max(ss)]
    else:
        bite += 1
        tot += 2 * (n - bite) - 1
dmax = {}
t = 0

cmax = Counter(smax)

for i in range(100001, -1, -1):
    if i in cmax.keys():
        t += cmax[i]
    dmax[i] = t
for i in smin:
    try:
        tot += dmax[i + 1]
    except:
        pass
print(tot)
