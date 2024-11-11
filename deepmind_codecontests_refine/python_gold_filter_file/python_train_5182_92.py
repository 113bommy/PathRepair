N, K = map(int, input().split())
P = list(map(lambda s: int(s) - 1, input().split()))
C = list(map(int, input().split()))

ans = -1_000_000_000
for i in range(N):
    S = [C[i]]
    p = P[i]
    while p != i:
        S.append(C[p])
        p = P[p]
    s = sum(S)
    n = len(S)
    acc = 0
    for i in range(min(n, K + 2)):
        acc += S[i]
        a = acc
        if s > 0:
            a += s * ((K - (i + 1)) // n)
        ans = max(a, ans)

print(ans)
