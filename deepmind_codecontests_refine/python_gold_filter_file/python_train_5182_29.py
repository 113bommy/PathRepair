N, K = map(int, input().split())
P = list(map(int, input().split()))
for i in range(N):
    P[i] -= 1
C = list(map(int, input().split()))
 
ans = -(10 ** 18)
 
for si in range(N):
    x = si
    loop = []
    total = 0
    while 1:
        x = P[x]
        loop.append(C[x])
        total += C[x]
        if x == si:
            break
    T = len(loop)  # 周期の大きさ
    tmp = 0
    for i in range(T):
        tmp += loop[i]
        if K < i + 1:
            break
        now = tmp
        if total > 0:  # loopの和が正ならloopを回した方がお得
            loop_times = (K - (i + 1)) // T  # 何周できるか
            now += total * loop_times
        ans = max(ans, now)
 
print(ans)