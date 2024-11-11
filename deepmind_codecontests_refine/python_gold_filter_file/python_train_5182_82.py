from itertools import accumulate

N, K, *PC = map(int, open(0).read().split())
P, C = [0] + PC[:N], [0] + PC[N:]

ans = float("-inf")
for start in range(1, N + 1):
    path = []

    cur = P[start]
    path = [C[start]]
    while cur != start:
        path.append(C[cur])
        cur = P[cur]

    A = list(accumulate(path))
    q, r = divmod(K, len(path))
    res = 0
    if A[-1] >= 0:
        if r == 0:
            q -= 1
            r += len(path)
        res += A[-1] * q
    elif q >= 1:
        r = len(path)

    ans = max(ans, res + max(A[:r]))

print(ans)