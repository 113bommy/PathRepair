N, K = map(int, input().split())
X = []
Y = []
XY = []
for _ in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)
    XY.append((x, y))

X = sorted(X)
Y = sorted(Y)
mi = 1<<200
for i in range(N):
    for j in range(i+1, N):
        for k in range(N):
            for l in range(k+1, N):
                s = 0
                for x, y in XY:
                    if X[i] <= x <= X[j] and Y[k] <= y <= Y[l]:
                        s += 1
                if s >= K:
                    mi = min(mi, (X[j] - X[i]) * (Y[l] - Y[k]))

print(mi)
