N, M, K = map(int, input().split())
P = 10**9+7
fact = [1]
for i in range(N*M):
    fact.append(fact[-1]*(i+1))
def inv(n):
    return pow(n, P-2, P)
def C(a, b):
    return fact[a]*inv(fact[a-b]*fact[b])%P
print((M**2*(N**3-N)+N**2*(M**3-M))//6*C(M*N-2, K-2)%P)