from collections import Counter
N = int(input())
As = list(map(int, input().split()))

MOD = 10 ** 9 + 7

factorials = [1]
fact_invs = [1]
for i in range(1, N+2):
    factorials.append((factorials[-1]*i) % MOD)
    fact_invs.append(pow(factorials[-1], MOD-2, MOD))
fact_invs.append(1)

def combi(n, k):
    if n < k:
        return 0
    ret = factorials[n]
    ret *= fact_invs[k]
    ret %= MOD
    ret *= fact_invs[n-k]
    return ret % MOD

ct = Counter(As)
mc = ct.most_common(1)[0][0]

L = R = None
for i, a in enumerate(As):
    if a == mc:
        if L is None:
            L = i
        else:
            R = N - i

for k in range(1, N+2):
    print(combi(N+1, k) - combi(L+R, k-1))
