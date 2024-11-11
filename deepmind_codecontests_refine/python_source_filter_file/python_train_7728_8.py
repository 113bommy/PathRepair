n = int(input())
mod = 998244353
pow10 = [1]
for i in range(1, 200005 + 1):
    pow10.append((pow10[i - 1] * 10) % mod)
if n == 1:
    print(10)
elif n == 2:
    print(180, 10)
else:
    for i in range(1, n):
        curr = 0
        diffs = n - (i - 1) - 2
        curr += 9 * pow10[n - i - 1]*10**2
        curr += 81* pow10[n - i - 2]*10 * diffs
        print(curr%mod, end=' ')
    print(10)