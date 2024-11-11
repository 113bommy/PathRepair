#ref : https://atcoder.jp/contests/abc128/submissions/5694292
#工事を座標順に処理，工事にぶつかる人をにぶたん
#すでに更新済みだったら更新しない．-> jumpで管理
from bisect import bisect_left
N, Q = map(int, input().split())
consts = []
for _ in range(N):
    s,t,x = map(int, input().split())
    consts.append((x,s,t))
consts.sort()
D=[int(input()) for _ in range(Q)]
ans=[-1]*Q
jump=[-1]*Q
for x,s,t in consts:
    left=bisect_left(D,s-x)
    right=bisect_left(D,t-x)
    while left<right:
        if jump[left]==-1:
            ans[left]=x
            jump[left]=right
            left += 1
        else:
            left=jump[left]
print(*ans, sep='\n')