#This code sucks, you know it and I know it.  
#Move on and call me an idiot later.

MOD = 1000000007
def fast_power(base, power):
    result = 1
    while power > 0:
        if power % 2 == 1:
            result = (result * base) % MOD

        power = power // 2
        base = (base * base) % MOD

    return result

x, k = map(int, input().split())

if x == 0 or k == 0:
    print((x * 2) % MOD)
else:
    d = ((x * 4) - 1) - (x * 2)
    print(((x * 2) + (d * (fast_power(2, k) - 1))) % MOD)