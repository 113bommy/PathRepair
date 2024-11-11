import math
def comb(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

N,K=map(int,input().split())
div=10**9+7

for i in range(K):
    if N-K+<i:
        print(0)
    else:
        print(comb(K-1,i)*comb(N-K+1,i+1)%div)