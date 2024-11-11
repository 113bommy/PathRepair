from math import ceil
import bisect


N, D, A = map(int, input().split())
L = [list(map(int, input().split())) for _ in range(N)]
L = [[pos, ceil(hp/A)] for pos, hp in L]
L = sorted(L, key=lambda pos: pos[0])

POS = [v[0] for v in L]
ES = [0]*(N+1)
ans, c = 0, 0
for i in range(N):
    c -= ES[i]
    if L[i][1] > A*c:
        t = L[i][1]-A*c
        ans += t
        c += t
        ES[bisect.bisect_right(POS, POS[i]+2*D)] += t
print(ans)
