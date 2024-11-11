a = input()
ln = len(a)
ans = 0
mod = 10**9 + 7
mul = [0] * ln
prev = 1
pow10 = [1] * ln
for i in range(ln):
    mul[i] = prev * (i + 1)
    if i > 0:
        mul[i] += mul[i - 1]
        pow10[i] = pow10[i - 1] * 10
        pow10[i]%=mod
    mul[i]%=mod
    prev *= 10
    prev%=mod
ans = 0
for i in range(ln):
    cur = (i%mod * (i + 1)%mod) // 2
    cur *= int(a[i])
    cur%=mod
    cur *= pow10[ln - i - 1]
    ans += cur%mod
    if i < ln-1:
        ans += (int(a[i]) * mul[ln - i - 2]) % mod
    ans%=mod
print(ans % mod)