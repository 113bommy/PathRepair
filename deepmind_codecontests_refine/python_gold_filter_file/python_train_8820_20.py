x, k = map(int, input().split())
MOD = 1000000007
pw = pow(2, k + 1, MOD)
n = pow(2, k, MOD)
a = (pw * x) - n
a = (a + 1) % MOD
if x == 0:
    a = 0
print(int(a))
