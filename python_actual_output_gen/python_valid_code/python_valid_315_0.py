t = int(input())
while t > 0:
    a, b, c = input().split()
    a = int(a)
    b = int(b)
    c = int(c)
    n = 0
    if a > 0:
        a -= 1
        n += 1
    if b > 0:
        b -= 1
        n += 1
    if c > 0:
        c -= 1
        n += 1
    if a > b:
        d = a
        a = b
        b = d
    if a > c:
        d = a
        a = c
        c = d
    if a> 0 and b> 0:
        a -= 1
        b -= 1
        n += 1
    if a >0 and c>0:
        a -= 1
        c -= 1
        n += 1
    if b>0 and c>0:
        b -= 1
        c -= 1
        n += 1
    if a> 0 and b> 0 and c > 0:
        n += 1
    print(n)
    t -= 1
