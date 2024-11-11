n, k, l, c, d, p, nl, np = map(int, input().split())
c1 = (k*l)//nl
c2 = c*d
c3 = p//np
def s():
    print(min(min(c1, c2), c3)//n)
s()
