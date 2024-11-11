from math import gcd
t = int(input())
 
for it in range(t):
    m, d, w = [int(i) for i in input().split()]
    w = w // gcd(w, d - 1)
    m = min(m, d)
    c = m // w
    print(c * m - w * c * (c + 1) // 2)