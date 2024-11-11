N, K = map(int, input().split())
P = [tuple(map(int, input().split())) for _ in range(N)]
P.sort()

ans = float('inf')
for i in range(N - K + 1):
    for j in range(i + K - 1, N):
        x = P[j][0] - P[i][0]
        if x == 0:
            continue

        Q = P[i: j + 1]
        Q.sort(key=lambda q: q[1])
        y = Q[-1][1] - Q[0][1]
        for k in range(0, len(Q) - K + 1):
            for l in range(k + K - 1, len(Q)):
                ny = Q[l][1] - Q[k][1]
                if ny == 0:
                    continue
                y = min(y, ny)
        ans = min(ans, x * y)

print(ans)
