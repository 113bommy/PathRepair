import bisect
import sys
input = sys.stdin.buffer.readline
N,D,A= map(int,input().split())
XH = [list(map(int,input().split())) for i in range(N)]
XH.sort()
X,H = [list(x) for x in zip(*XH)]

ans = 0
cum = [0]*N
dam = 0
for i in range(N):
    dam += cum[i]
    H[i] -= dam
    x = X[i]
    if H[i] <= 0:
        continue
    cnt_bom = -(-H[i] // A)
    ans += cnt_bom
    damage = cnt_bom * A
    ind = bisect.bisect_right(X,x+2*D)
    if i+1 < N:
        cum[i+1] += damage 
    if ind < N:
        cum[ind] -= cnt_bom

print(ans)
