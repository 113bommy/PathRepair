import sys
import math
input = sys.stdin.readline
imp = 'IMPOSSIBLE'


t = int(input())

for test in range(t):
    n = int(input())
    a = list(map(int, input().split(" ")))
    jo = False
    if 0 in a:
        jo = True
    for i in range(n):
        for j in range(i + 1, n):
            if a[i] == a[j]:
                jo = True
                break
        if jo:
            break
    if not jo:
        ss = []
        for i in range(1, 2 ** n):
            ii = i
            aa = [0 for u in range(n)]
            for j in range(n):
                aa[j] = ii % 2
                ii //= 2
            # print(aa)
            su = 0
            for k in range(n):
                su = su + a[k] * aa[k]
            #print(su)
            ss.append(su)
        ss.sort()
        for k in range(len(ss) - 1):
            if ss[k] == ss[k + 1]:
                jo = True
                break
    if jo:
        print('YES')
    else:
        print('NO')
