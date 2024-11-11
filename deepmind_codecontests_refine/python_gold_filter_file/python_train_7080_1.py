from math import sqrt
n = int(input())
p1 = complex(0, 0)
p2 = complex(100, 0)
phi = complex(1/2, sqrt(3)/2)

def makeCurve(p1, p2, cnt):
    if cnt >= n:
        return
    s = p1 + (p2-p1)/3
    t = p1 + (p2-p1)*2/3
    u = (t-s)*phi+s
    
    
    makeCurve(p1, s, cnt + 1)
    print(s.real, s.imag)
    makeCurve(s, u, cnt + 1)
    print(u.real, u.imag)
    makeCurve(u, t, cnt + 1)
    print(t.real, t.imag)
    makeCurve(t, p2, cnt + 1)

print(p1.real, p1.imag)
makeCurve(p1, p2, 0)
print(p2.real, p2.imag)
