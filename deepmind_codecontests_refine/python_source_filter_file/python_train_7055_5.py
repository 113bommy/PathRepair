def makefac(n):
    global faclist
    faclist = [1, 1]
    for i in range(2, n + 1):
        faclist.append(faclist[-1] * i % MOD)
    return None
def mcomb(n, r):#nCr % MOD
    return faclist[n] * pow(faclist[r],MOD - 2,MOD) * pow(faclist[n-r], MOD - 2) % MOD
def mperm(n, r):#nPr % MOD
    return faclist[n] * pow(faclist[n-r],MOD - 2, MOD)

N, M = map(int, input().split())
MOD = 10 ** 9 + 7
makefac(M)
ans = mperm(M, N)
for k in range(1, N + 1):
    ans += ((-1)**k * mcomb(N, k) * mperm(M - k, N - k)) % MOD
ans = ans * mperm(M, N) % MOD
print(ans)
