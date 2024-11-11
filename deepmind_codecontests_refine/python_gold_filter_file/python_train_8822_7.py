MOD = int(1e9)+7

def fast_power(x, y):
    res = 1
    x %= MOD
    while y > 0:
        if y % 2 == 1:
            res = (res * x) % MOD
        x = (x * x) % MOD
        y = y >> 1
    return res
 
x, k = map(int, input().split())
if(x == 0):
    print(0)
else:
    a = fast_power(2, k)
    b = (2 * x - 1) % MOD
    c = (a * b) % MOD + 1
    print(c % MOD)
