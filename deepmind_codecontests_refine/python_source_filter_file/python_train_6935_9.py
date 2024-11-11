def main():
    m1, m2, m3, t1, t2 = tuple(map(int, input().split()))
    t1 *= 3600
    c = 3600*12
    t2 = (t2 * 3600) % c
    l = [(m1 * 3600) % c, (m2 * 3600 / 5) % c, (m3 * 3600 / 5)]
    def ans(p):
        last = 100000000
        if t1 in l and p == 1:
            return False
        for i in range(c):
            cc = (t1 + i*p) % c
            
            if last in l or last - c in l:
                return False
            if cc == t2:
                if t2 in l:
                    return p == 1
                return True
            if i > 1: last = cc - p
    return "YES" if ans(1) or ans(-1) else "NO"
print(main())
