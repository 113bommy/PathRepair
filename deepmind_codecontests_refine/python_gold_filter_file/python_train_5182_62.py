N, K = map(int, input().split())
P = list(map(int, input().split()))
C = list(map(int, input().split()))

# 一度たずねた場所はループが判明しているのでそのままにする(何度移動させるかに関係なくtree構造がつながっているかを調べたい)
ans = -10 ** 18
for i in range(N):
    x = i
    loop = []
    total = 0
    while True:
        x = P[x] - 1
        loop.append(C[x])
        total += C[x]
        if x == i:
            break

    T = len(loop)
    tmp = 0
    for j in range(T):
        tmp += loop[j]
        if K < j + 1:
            break
        now = tmp
        # 一周のループが正の時のみ何度も回す価値がある。それ以外のときはそれまでの最大をとる
        if total > 0:
            loop_times = (K - (j + 1)) // T
            now += total * loop_times

        ans = max(ans, now)
print(ans)
