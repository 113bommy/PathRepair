n = int(input())
import collections
dat = []
for i in range(n):
    dat.append(dict())
for i in range(n):
    buf = list(map(int, input().split()))
    for x in buf[1:]:
        dat[i][x] = True
res = 0
final = []
for k in dat[i].keys():
    can = True
    for i in range(n):
        if k not in dat[i]:
            can = False
    if can:
        final.append(str(k))
print(" ".join(final))


