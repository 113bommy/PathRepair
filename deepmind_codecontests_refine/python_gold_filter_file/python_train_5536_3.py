from sys import stdin
from sys import setrecursionlimit as SRL; SRL(10**7)
rd = stdin.readline
rrd = lambda: map(int, rd().strip().split())

n = int(input())
a = list(rrd())


op = []
q = int(input())

for i in range(q):
    c = list(rrd())
    op.append(c)


sure = [-1] * (n+1)
hi = 0
for i in range(q-1,-1,-1):
    if op[i][0] == 1:
        cnt = op[i][1]
        if sure[cnt] is -1:
            sure[cnt] = max(op[i][2],hi)
    else:
        hi = max(hi,op[i][1])


for i in range (1,n+1):
    if sure[i] is -1:
        sure[i] = max(hi,a[i-1])

    print(sure[i])


