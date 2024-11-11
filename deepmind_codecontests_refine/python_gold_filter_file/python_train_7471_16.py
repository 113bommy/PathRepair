MOD = 10**9+7

s = int(input())
a = [0]*(s+1)
a[0] = 1
for i in range(3, s+1):
    a[i] = sum(a[:i-2]) % MOD
print(a[s])
