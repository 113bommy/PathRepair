MOD = 1000000007

def binpow(a, b, m):
    a = a % m
    res = 1
    while b > 0:
        if (b & 1):
            res = res * a % m
        a = a * a % m
        b >>= 1
    return res


# if __name__ == '__main__':
k = int(input())
if k == 1:
    print(6)
else:
    t1 = -1 * (1 - pow(2, k, MOD)) - 1
    t = binpow(4,t1,MOD) * 6 % MOD
    print(t)

