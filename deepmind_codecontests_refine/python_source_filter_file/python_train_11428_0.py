n, x, m = map(int, input().split())
S = [0]
F = [None] * m
for i in range(m):
    S.append(S[-1] + x)
    if F[x] is not None:
        j = F[x]
        q, r = (n - j) // (i - j), (n - j) % (i - j)
        print((S[i] - S[j]) * q + S[j + r])
        exit()
    F[x] = i
    x = pow(x, 2, m)
