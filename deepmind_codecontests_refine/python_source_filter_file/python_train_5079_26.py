import sys
input = sys.stdin.readline
N, D, A = map(int, input().split())
XH = [list(map(int, input().split())) for _ in range(N)]
#XH.sort()
X = [XH[i][0] for i in range(N)]
ans = 0
res = 0
from bisect import bisect_left
cnt = [0]*(N+1)
for i in range(N):
    x, h = XH[i]
    res-=cnt[i]
    h-=res
    if h<=0:
        continue
    n = ((h-1)//A+1)
    j = bisect_left(XH, [x+D*2+1, -1])
    cnt[j] += n*A
    res += n*A
    ans+=n
print(ans)
    



