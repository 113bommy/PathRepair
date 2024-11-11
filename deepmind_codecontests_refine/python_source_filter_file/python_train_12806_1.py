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
T = input(); P = input()
MOD = 10**9+7
HT = RH(T, 3, MOD)
HP = RH(P, 3, MOD)

pv = HP.calc(0, len(P))
calc = HT.fixed(len(P))
for i in range(len(T)-len(P)+1):
    if calc(i) == pv:
        print(i)