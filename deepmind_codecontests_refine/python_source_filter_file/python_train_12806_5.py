import random, math
random.seed()
def gen(a, b, num):
    result = set()
    while 1:
        while 1:
            v = random.randint(a, b)//2*2+1
            if v not in result:
                break
        for x in range(3, int(math.sqrt(v))+1, 2):
            if v % x == 0:
                break
        else:
            result.add(v)
            if len(result) == num:
                break
    return result
class RH():
    def __init__(self, s, base, mod):
        self.base = base
        self.mod = mod
        self.rev = pow(base, mod-2, mod)

        l = len(s)
        self.h = h = [0]*(l+1)
        tmp = 0
        for i in range(l):
            num = ord(s[i])
            tmp = (tmp*base + num) % mod
            h[i+1] = tmp
    def calc(self, l, r):
        return (self.h[r] - self.h[l] * pow(self.base, r-l, self.mod)) % self.mod
    def fixed(self, length):
        v = pow(self.base, length, self.mod)
        h = self.h; mod = self.mod
        def fixed_calc(l):
            return (h[length+l] - h[l] * v) % mod
        return fixed_calc
class RRH():
    def __init__(self, s, num=10, primes=None):
        primes = primes or gen(2, 10**3, num)
        MOD = 10**9+7
        self.rhs = [RH(s, p, MOD) for p in primes]
    def calc(self, l, r):
        return [rh.calc(l, r) for rh in self.rhs]
    def fixed(self, length):
        fs = [rh.fixed(length) for rh in self.rhs]
        def multi_fixed_calc(l):
            return list(f(l) for f in fs)
        return multi_fixed_calc

T = input(); P = input()
primes = gen(2, 10**3, 3)
HT = RRH(T, primes=primes)
HP = RRH(P, primes=primes)

pv = HP.calc(0, len(P))
calc = HT.fixed(len(P))
for i in range(len(T)-len(P)+1):
    if calc(i) == pv:
        print(i)