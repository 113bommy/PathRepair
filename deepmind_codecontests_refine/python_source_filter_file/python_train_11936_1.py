

c_mod = 1000000007

def InverseMod(b: int, m: int):
    b %= m
    if b == 0 or b == 1: return b

    a = m
    qs = []
    while True:
        q = a // b
        r = a % b
        if (r == 0): break
        a = b
        b = r
        qs.append(q)

    qA = 1
    qB = -qs[len(qs) - 1]
    for i in range(len(qs) - 2, -1, -1):
        t = qA
        qA = qB
        qB = qB*(-qs[i]) + t
    
    qB %= m
    if qB < 0: 
        qB = m + qB
    return qB

def save_mul(a, b):
    return (a * b) % c_mod


class Fraction:
    def __init__(self, a: int, b: int, dBase: int, dPow: int):
        self.a, self.b, self.dBase, self.dPow = a, b, dBase, dPow
    
    def __add__(self, other):
        f = Fraction(self.a, self.b, self.dBase, self.dPow)
        if f.dPow > other.dPow:
            f.a += other.a * (f.dBase ** (f.dPow - other.dPow))
            f.a %= c_mod
        elif f.dPow < other.dPow:
            f.a = f.a * (f.dBase ** (other.dPow - f.dPow)) + other.a
            f.b = other.b
            f.dPow = other.dPow
            f.a %= c_mod
        else:
            f.a += other.a
            f.a %= c_mod
        return f
    
    def __mul__(self, other):
        f = Fraction(self.a, self.b, self.dBase, self.dPow)
        f.a *= other.a
        f.b *= other.b
        f.dPow += other.dPow
        f.a %= c_mod
        f.b %= c_mod
        return f
    
    def __str__(self):
        return "{0}/{1}".format(self.a, self.b)



def main():
    '''f1 = Fraction(6, 5)
    f2 = Fraction(5, 5)
    f1.dPow = 2
    f1.b = 25
    print(f1 + f2)
    print(f1)'''

    s = str(input()).split()
    n, m = int(s[0]), int(s[1])
    s1 = str(input()).split()
    s2 = str(input()).split()
    r = Fraction(0, 1, m, 0)
    k = Fraction(1, 1, m, 0)

    for i in range(n):
        u = int(s1[i])
        d = int(s2[i])
        if u == 0 and d == 0:
            f = Fraction(m * (m - 1) / 2, m * m, m, 2)
            f = f * k
            r = r + f
            k.b = save_mul(k.b, m)
            k.dPow += 1
            continue
        elif u == 0:
            f = Fraction(m - d, m, m, 1)
            f = f * k
            r = r + f
            k.b = save_mul(k.b, m)
            k.dPow += 1
            continue
        elif d == 0:
            f = Fraction(u - 1, m, m, 1)
            f = f * k
            r = r + f
            k.b = save_mul(k.b, m)
            k.dPow += 1
            continue
        
        if u > d:
            r = r + k

        if u != d: break
    
    print(save_mul(r.a, InverseMod(r.b, c_mod)))


main()
