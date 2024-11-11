def shorten(s):
    f = 1
    while f:
        l = len(s) // 2
        while f:
            f = 0
            if l % 2 == 0:
                for i in range(l):
                    if s[2 * i:2 * i + 2] != "00" and i % 2:break
                else:
                    f = 1
                    t = ""
                    for i in range(0, l, 2):t += s[2 * i:2 * i + 2]
                    s = t
                    l = len(s) // 2
        for k in range(3, l + 1, 2):
            f = 1
            while f:
                f = 0
                if l % k == 0:
                    for i in range(l):
                        if s[2 * i:2 * i + 2] != "00" and i % k:break
                    else:
                        f = 1
                        t = ""
                        for i in range(0, l, k):t += s[k * i:k * i + 2]
                        s = t
                        l = len(s) // 2
    return s

def lcm(a, b):
    p, q = max(a, b), min(a, b)
    while 1:
        if p % q:p, q = q, p % q
        else: return a * b // q

for _ in range(int(input())):
    n = int(input())
    r = [shorten(input()) for _ in range(n)]
    ls = [len(i) // 2 for i in r]
    l = ls[0]
    for i in range(1, len(r)):l = lcm(l, ls[i])
    if l > 1024:print("Too complex.");continue
    a = [0] * l
    for i in range(n):
        d = l // ls[i]
        for j in range(ls[i]):a[d * j] += int(r[i][2 * j: 2 * j + 2], 16)
    s = ""
    for i in a:s += format(i,"02X")
    print(s)
