MOD = 1000000009

def inv(n):
    return pow(n, MOD - 2, MOD)

n, a, b, k = map(int, input().split())
q = (n + 1) // k
string = input()
s = []
for char in string:
    if char == "+": s.append(1)
    else: s.append(-1)
    
res = 0 # final answer

for i in range(k):
    res += (s[i] * pow(a, n - i, MOD) * pow(b, i, MOD))
    res %= MOD

n1 = pow(b, k, MOD)
n2 = pow(a, k, MOD)
n2 = inv(n2)
T = n1 * n2 % MOD

if a != b or T != 1:
    num = (pow(b, n + 1, MOD) - pow(a, n + 1, MOD)) % MOD # numerator
    d1 = (pow(b, k, MOD) - pow(a, k, MOD)) % MOD
    d1 = inv(d1)
    d2 = pow(a, n + 1 - k, MOD)
    d2 = inv(d2)

    R = (num * d1 * d2) % MOD

    res = (res * R) % MOD

    print(res)

else:
    res *= q
    res %= MOD
    print(res)
    
