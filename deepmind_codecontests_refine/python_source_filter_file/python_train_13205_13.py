fact = [1] * 51
for i in range(2, 51):
    fact[i] = fact[i-1] * i

def Combination(n, k):
    return fact[n] // fact[k] // fact[n-k]

N, A, B = map(int, input().split())
v = sorted(list(map(int, input().split())))[::-1]
MAX = sum(v[:A])
print(MAX/A)
M = max(v[:A])
m = min(v[:A])
if M != m:
    c1, c2 = v[:A].count(m), v.count(m)
    print(Combination(c2, c1))
else:
    c = v.count(m)
    L = min(B, c)
    ans = 0
    for i in range(1, L+1):
        ans += Combination(c, i)
    print(ans)
