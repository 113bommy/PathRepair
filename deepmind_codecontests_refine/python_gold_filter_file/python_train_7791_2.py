MOD = 10**9 + 7
N, M = map(int, input().split())
S = [[N]*(N+1) for i in [0,1,2]]
T = [[0]*(N+1) for i in [0,1,2]]

C = [0]*(N+1)
for i in range(M):
    l, r, x = map(int, input().split())
    S[x-1][r] = min(S[x-1][r], l)
    T[x-1][r] = max(T[x-1][r], l)
    C[r] = 1

S0, S1, S2 = S
T0, T1, T2 = T

ok = 1
for i in range(N+1):
    if not T2[i] < S1[i] or not T1[i] < S0[i]:
        ok = 0
        break

if not ok:
    print(0)
    exit(0)


X = {(0, 0): 3}
for b in range(1, N):
    t2 = T2[b+1]; s1 = S1[b+1]; t1 = T1[b+1]; s0 = S0[b+1]
    check = lambda r, g: t2 <= r < s1 and t1 <= g < s0

    Z = [0]*(N+1)
    if C[b+1]:
        if t1 <= b < s0:
            for (r, g), v in X.items():
                if t2 <= g < s1:
                    # r <- b+1
                    Z[g] += v
                if t2 <= r < s1:
                    # g <- b+1
                    Z[r] += v
        X = {(r, g): v for (r, g), v in X.items() if t2 <= r < s1 and t1 <= g < s0}
    else:
        Z = [0]*(N+1)
        for (r, g), v in X.items():
            # r <- b+1
            Z[g] += v
            # g <- b+1
            Z[r] += v;
    for z, v in enumerate(Z):
        if v:
            X[z, b] = v % MOD
print(sum(X.values()) % MOD)