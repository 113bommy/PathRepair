from collections import Counter
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


N, M = map(int, input().split())
mat = [list(map(lambda x:int(x)-1, input().split())) for _ in range(N)]

ans = N
Q = [set([v for v in range(M)])]
while Q:
    C = Counter()
    sports_cand = Q.pop(0)
    for n in range(N):
        for m in range(M):
            if mat[n][m] in sports_cand:
                C[mat[n][m]] += 1
                break
    tmp = 0
    rem_key = {}
    for key, val in C.most_common():
        if val >= tmp:
            tmp = val
            ans = min(ans, val)
            rem_key.add(key)
        else:
            break
    if len(sports_cand) > 2:
        Q.append(sports_cand-rem_key)
print(ans)
