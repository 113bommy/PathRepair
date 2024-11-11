import sys
import math
import collections
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

r = sys.stdin.readline

for _ in range(int(r())):
    N, K = map(int, r().split())
    L = list(map(int, r().split()))
    LL = []
    ans = [0]*(N+1)
    d = {}
    can = 0
    for i in range(N):
        LL.append([L[i], i])
        try: d[L[i]] += 1
        except: d[L[i]] = 1
        if d[L[i]] <= K:
            can += 1

    can //= K
    can -= 1
    LL.sort()
    dic = {}
    idx = 1
    for i in range(N):
        try:
            dic[LL[i][0]] += 1
        except:
            dic[LL[i][0]] = 1
        if dic[LL[i][0]] > 5: continue
        ans[LL[i][1]] = idx
        if idx >= K:
            if can:
                can -= 1
                idx = 0
            else:
                break
        idx += 1
    for i in range(N):
        print(ans[i], end= " ")
    print()

