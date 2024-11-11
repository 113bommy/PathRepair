n = int(input())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]

mod = 998244353

ans = 0

for i in range(n):
    right = n-i-1
    left = i
    A[i] = ((1+right)*(1+left)*A[i])

newB = [[B[i], i] for i in range(n)]
newA = [[A[i], i] for i in range(n)]

sortedB = sorted(newB, reverse = True)
sortedA = sorted(newA)

for i in range(n):
    B[sortedA[i][1]] = sortedB[i]

B = [B[i][0] for i in range(n)]

pref_prod = [1]
pair_prods = []

for i in range(n+1):
    pdt = (pref_prod[-1] * A[i-1])%mod
    pref_prod.append(pdt)
    if i<n:
        pair_prods.append(A[i]*B[i])
ans = 0

for i in range(n):
    ans %= mod
    ans += (pair_prods[i])%mod

print(ans%mod)


