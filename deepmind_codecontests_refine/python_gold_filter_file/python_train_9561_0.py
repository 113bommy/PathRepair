N, K = map(int, input().split())
X, Y = [], []
D = []
for i in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)
    D.append((x, y))

X = sorted(X)
Y = sorted(Y)
num = float("inf")
for i in range(N - 1):
    for j in range(i + 1, N):
        for k in range(N - 1):
            for l in range(k + 1, N):
                tmp = 0
                for m in range(N):
                    if X[i] <= D[m][0] <= X[j] and Y[k] <= D[m][1] <= Y[l]:
                        tmp += 1
                if tmp >= K:
                    num = min(num, (X[j] - X[i]) * (Y[l] - Y[k]))

print(num)