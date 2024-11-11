def solve():
    N = int(input())
    Ass = [tuple(map(int, input().split())) for _ in range(N)]

    scores = [0] * (1<<N)
    for S in range(1, 1<<N):
        for i in range(N):
            if (S>>i) & 1:
                score = scores[S ^ (1<<i)]
                for j in range(i+1, N):
                    if (S>>j) & 1:
                        score += Ass[i][j]
                scores[S] = score
                break

    def enumSubset(S):
        subSs = []
        subS = S
        while True:
            subSs.append(subS)
            subS = (subS-1) & S
            if subS == S:
                break
        subSs.reverse()
        return subSs

    dp = [0] * (1<<N)
    for S in range(1<<N):
        subSs = enumSubset(S)
        dp[S] = max([scores[subS] + dp[S-subS] for subS in subSs])

    print(dp[-1])


solve()
