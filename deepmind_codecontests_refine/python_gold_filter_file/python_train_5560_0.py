def main():
    mod = (10 ** 9) + 7
    lim = 20200

    fct = [0] * lim
    inv_f = [0] * lim

    fct[0] = 1
    for i in range(1, lim):
        fct[i] = fct[i - 1] * i % mod

    inv_f[lim - 1] = pow(fct[lim - 1], mod - 2, mod)

    for i in range(lim - 1, 0, -1):
        inv_f[i - 1] = inv_f[i] * i % mod

    def nCk(a, b):
        if b == 0:
            return 1
        else:
            return fct[a] * inv_f[b] * inv_f[a - b] % mod

    def nPk(a, b):
        return fct[a] * inv_f[a - b] % mod

    n = int(input())
    s = list(map(int, input().split()))
    ind, rem = set(), set()
    for i, x in enumerate(s):
        if x == -1:
            ind.add(i + 1)
        else:
            rem.add(x)
    dif = set(range(1, n + 1)) - rem
    #print(ind, dif)
    k = len(ind)
    l = len(ind&dif)
    res = 0
    for i in range(l + 1):
        #print(i, fct[k - i], nCk(k, i))
        tmp = fct[k - i] * nCk(l, i) % mod
        if i & 1:
            res -= tmp
        else:
            res += tmp
    print(res % mod)

if __name__ == '__main__':
    main()
