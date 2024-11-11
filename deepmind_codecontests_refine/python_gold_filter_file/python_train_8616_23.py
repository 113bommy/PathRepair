k = int(input())
s = input()
n = len(s)
MOD = 10 ** 9 + 7

ans = 0
comb = 1
for i in range(k+1):
    if i > 0: comb = comb * (n+i-1) * pow(i, MOD-2, MOD) % MOD
    ans = (ans + comb * pow(25, i, MOD) * pow(26, k-i, MOD)) % MOD
print(ans)
