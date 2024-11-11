N, K = map(int, input().split())
X = []
Y = []
for _ in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)
Xs = sorted(X)
Ys = sorted(Y)
ans = float('inf')
for left in range(N - 1):
    for right in range(left + 1, N):
        for down in range(N - 1):
            for up in range(down + 1, N):
                count = 0
                for i in range(N):
                    if Xs[left] <= X[i] <= Xs[right] and Ys[down] <= Y[i] <= Ys[up]:
                            count += 1
                if count >= K:
                    ans = min(ans, (Xs[right] - Xs[left]) * (Ys[up] - Ys[down]))
print(ans)