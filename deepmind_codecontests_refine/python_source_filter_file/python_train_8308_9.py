N = int(input())
X = [0] * N
for i in range(N):
    a = int(input()) - 1
    X[a] = i

ma = 0
s = X[0]
for i in range(1, N):
    if X[i] < X[i-1]: s = i
    ma = max(ma, i - s + 1)

print(N - ma)