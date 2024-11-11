N, K = list(map(int, input().split()))
A = list(map(lambda x: int(x) - 1, input().split()))

v = [A[:]]
now = 0
for i in range(60):
    v.append([v[i][v[i][j]] for j in range(N)])
    if K>>i & 1:
        now = v[i][now]
print(now + 1)