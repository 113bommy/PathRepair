x, k = [int(z) for z in input().split()]
MOD = 1000000007

def bigmod(a,b,m):
    ans = 1
    rem = a%m

    while b != 0:
        if b%2 == 1:
            ans = (ans * rem) % m
        
        rem = (rem * rem) % m

        b //= 2

    return ans

if k == 0:
    print(x * 2)
elif x == 0:
    print(0)
else:
    pot = bigmod(2, k, MOD)
    a0 = ((x * pot)%MOD - pot + 1)%MOD
    res = (((a0 * 2)%MOD + pot)%MOD - 1)%MOD
    print(res)
