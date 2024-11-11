N = int(input())
LRs = [tuple(map(int, input().split())) for _ in range(N)]


# [L1, R1]は最小のRを、[L2, R2]は最大のLを含む。L1を減らす形で走査。
R1 = min(map(lambda t: t[1], LRs))
L2 = max(map(lambda t: t[0], LRs))
LRs.sort(key=lambda t: (-t[0], t[1])) # Lについて降順、L同じならRについて昇順

ans = 0
R2 = 1001001001
for i in range(1, N-1):
    R2 = min(R2, LRs[i-1][1])
    L1 = LRs[i][0]  # LRsはLについて降順ソート済みより
    ans = max(ans, max(0, R2 - L2 + 1) + max(0, R1 - L1 + 1))


# 加えて、コンテスト1つだけ行うときを場合分け
LRs.sort(key = lambda t: t[0] - t[1])
one_problem_contest = LRs[0][1] - LRs[0][0] + 1
L_max = max(map(lambda t: t[0], LRs[1:]))
R_min = min(map(lambda t: t[1], LRs[1:]))
ans = max(ans, one_problem_contest + max(R_min - L_max + 1, 0))

print(ans)
