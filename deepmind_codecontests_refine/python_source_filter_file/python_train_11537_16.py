import bisect
A,B,Q = map(int,input().split())
INF = float('inf')
S = [-INF]+[int(input()) for _ in range(A)]+[INF]
T = [-INF]+[int(input()) for _ in range(B)]+[INF]

ans = []
for q in range(Q):
    x = int(input())
    i = bisect.bisect_right(S,x)
    j = bisect.bisect_right(T,x)
    d = INF
    for s in [S[i-1],S[i]]:
        for t in [T[i-1],T[i]]:
            d1 = abs(x-s) + abs(s-t)
            d2 = abs(x-t) + abs(s-t)
            d = min(d,d1,d2)
    ans.append(d)
print(*ans,sep="\n")