def f_polynomal_construction(P, A):
    class Combination(object):
        """参考: https://harigami.net/contents?id=5f169f85-5707-4137-87a5-f0068749d9bb"""
        __slots__ = ["mod", "factorial", "inverse"]

        def __init__(self, max_n: int = 10**6, mod: int = 10**9 + 7):
            fac, inv = [1], []
            fac_append, inv_append = fac.append, inv.append

            for i in range(1, max_n + 1):
                fac_append(fac[-1] * i % mod)

            inv_append(pow(fac[-1], mod - 2, mod))

            for i in range(max_n, 0, -1):
                inv_append(inv[-1] * i % mod)

            self.mod, self.factorial, self.inverse = mod, fac, inv[::-1]

        def combination(self, n, r):
            if n < 0 or r < 0 or n < r:
                return 0
            return self.factorial[n] * self.inverse[r] * self.inverse[n - r] % self.mod

    combination = Combination(P)
    comb = [combination.combination(P - 1, i) for i in range(P)]
    ans = [0] * P
    for j, a in enumerate(A):
        if a == 0:
            continue
        # 1-(x-j)^{p-1} = 1 - \sum_{k=0}^{p-1} comb(p-1, p-k-1) * x^{p-k-1} * (-j)^k
        # なので、定数項に1を足し、x^k の係数から各々引く
        # pow(-j, k, P) としたいが、時間がかかるので tmp に掛けていくことにする
        ans[0] += 1
        tmp = 1
        for k in range(P):
            index = P - k - 1
            if k > 0:
                tmp *= (-j)
                tmp %= P
            ans[index] -= comb[index] * tmp
            ans[index] %= P
    return ' '.join(map(str, ans))

P = int(input())
A = [int(i) for i in input().split()]
print(f_polynomal_construction(P, A))