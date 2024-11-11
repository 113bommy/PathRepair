
N, K = map(int, input().split())
X = list(map(int, input().split()))

x = X[:] + [0]
for _ in range(K):
    if all(v == N for v in x[:-1]):
        break

    new = [0] * (N + 1)
    for i in range(N):
        new[max(0, i - x[i])] += 1
        new[min(N, i + x[i] + 1)] -= 1

    for i in range(N):
        new[i + 1] += new[i]
    x = new[:]

print(*x)
