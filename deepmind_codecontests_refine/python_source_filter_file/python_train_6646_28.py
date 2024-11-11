from collections import Counter
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


N, M = map(int, input().split())
mat = [list(map(lambda x:int(x)-1, input().split())) for _ in range(N)]

ans = N
sports_cand = set([v for v in range(M)])
for _ in range(M-2):
    C = Counter()
    for n in range(N):
        for m in range(M):
            if mat[n][m] in sports_cand:
                C[mat[n][m]] += 1
                break
    tmp = 0
    key, val = C.most_common(1)[0]
    ans = min(ans, val)
    sports_cand -= {key}
print(ans)
