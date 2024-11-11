import sys
import math

st = (sys.stdin.readline())
k = int(sys.stdin.readline())

d = dict()
alla = 0
for i in range(len(st) - 1):
    if st[i] in d:
        d[st[i]] += 1
    else:
        d[st[i]] = 1
        alla += 1

f = sorted(d.items(), key = lambda x: x[1])

v = []
p = 0
for i in f:
    if(k - i[1] >= 0):
        v.append(i[0])
        k -= i[1]
        p += 1
    else:
        break

print(alla - p)
for i in range(len(st) - 1):
    fl = False
    for j in v:
        if(st[i] == j):
            fl = True
    if(not fl):
        sys.stdout.write(st[i])
       