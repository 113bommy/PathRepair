K = int(input())
S = input()
M = int(10 ** 9 + 7)

fact = [1]
for i in range(1, K + len(S) + 10):
    fact.append(fact[-1] * i % M)

finv = [pow(fact[-1], M - 2, M)]
for i in range(K + len(S) + 9, 0, -1):
    finv.append(finv[-1] * i % M)
finv.reverse()

def comb(a, b, m):
    return fact[a] * finv[b] % m * finv[a - b] % m

def hcomb(a, b, m):
    return comb(a + b - 1, a - 1, m)

ans = 0
for l in range(0, K + 1):
    ans += pow(26, l, M) * pow(25, K - l, M) % M * hcomb(len(S), K - l, M) % M
    ans %= M
print(ans)
