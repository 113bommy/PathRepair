import math
n = int(input())

def yakusu(n):
    a = []
    for i in range(1, int(math.sqrt(2*n))+2):
        if(2*n % i == 0):
            a.append(i)
    for i in range(len(a)):
        a.append(2*n // a[i])
    return sorted(list(set(a)))

def exgcd(a, b):
    if a == 0:
        return b, 0, 1
    else:
        g, y, x = exgcd(b % a, a)
        return g, x - (b // a) * y, y
    
def CRT(b1, m1, b2, m2):
    # 中国剰余定理
    # x ≡ b1 (mod m1) ∧ x ≡ b2 (mod m2) <=> x ≡ r (mod m)
    # となる(r. m)を返す
    # 解無しのとき(0, -1)
    d, p, q = exgcd(m1, m2)
    if (b2 - b1) % d != 0:
        return 0, -1
    m = m1 * (m2 // d)  # m = lcm(m1, m2)
    tmp = (b2-b1) // d * p % (m2 // d)
    r = (b1 + m1 * tmp) % m
    return r, m
x = yakusu(n)
a = 1e16
for i in range(len(x)):
    r, m = CRT(-1, 2*n//x[i], 0, x[i])
    if(r > 0):
        a = min(a, r)
print(a)