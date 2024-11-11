class Combination:
    '''
    計算量：階乗・逆元テーブルの作成O(N)
            nCkを求めるO(1)
    '''

    def __init__(self, n, MOD):
        self.fact = [1]
        for i in range(1, n + 1):
            self.fact.append(self.fact[-1] * i % MOD)
        self.inv_fact = [pow(self.fact[i] ,MOD - 2 ,MOD) for i in range(n + 1)]
        self.MOD = MOD

    def factorial(self, k):
        '''k!を求める'''
        return self.fact[k]

    def inverse_factorial(self, k):
        '''k!の逆元を求める'''
        return self.inv_fact[k]

    def combination(self, k, r):
        '''kCrを求める'''
        return (self.fact[k] * self.inv_fact[k - r] * self.inv_fact[r]) % self.MOD


n, a, b, k = map(int, input().split())
MOD = 998244353
comb = Combination(n, MOD)
ans = 0
for i in range(n+1):
    if not(k - a*i >= 0 and (k - a*i) % b == 0 and (k - a*i) // b <= n):
        continue
    else:
        ai = i
        bi = (k - a*i) // b
        ans += comb.combination(n, ai) * comb.combination(n, bi)
        ans %= MOD
print(ans)