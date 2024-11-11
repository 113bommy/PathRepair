from math import factorial

def cmb(n,k):
    if n < k or n < 0 or k < 0:
        return 0
    return int(factorial(n)/(factorial(k)*factorial(n-k)))

N, K = map(int, input().split())

for i in range(1, K+1):
    ans = cmb(K-1, i-1) * cmb(N-K+1, i)
    print(ans%(10**9+7))