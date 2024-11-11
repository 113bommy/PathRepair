# coding: utf-8
import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

# (と)の数は同じ、最下点に注目
N = ir()
S = [[1 if x == '(' else -1 for x in list(sr())] for _ in range(N)]
pos = []
neg = []
for s in S:
    temp = 0
    mi = 0
    for x in s:
        temp += x
        if temp < mi:
            mi = temp
    if temp >= 0:
        pos.append((mi, temp))
    else:
        neg.append((mi+temp, -temp))

pos.sort(reverse=True)
neg.sort(reverse=True)
cur_p = 0; cur_n = 0
bl = True
for m, p in pos:
    if cur_p + m < 0:
        bl = False
    cur_p += p

for m, n in neg:
    if cur_p + m < 0:
        bl = False
    cur_n += n

if cur_p != cur_n:
    bl = False

print('Yes' if bl else 'No')
