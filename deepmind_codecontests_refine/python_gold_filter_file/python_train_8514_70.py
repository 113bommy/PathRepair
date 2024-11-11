import sys
import bisect

ss = input()
t = input()
n = len(ss)
cnt = {}
s = ss*2

for i, x in enumerate(s):
    if x not in cnt:
        cnt[x] = []
    cnt[x].append(i)

idx = 0
ten = 0
#print(cnt)
for z in t:
    if z not in ss:
        print(-1)
        sys.exit()

    idx = cnt[z][bisect.bisect_left(cnt[z], idx)] + 1

    if idx>=n:
        idx -= n
        ten += 1

    #print(idx, z, ten)

suffix = idx + ten * n

print(suffix)