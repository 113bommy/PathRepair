t = int(input(''))
for k in range(0,t):
    p,q,r,s = input('').split(' ')
    n = int(p)
    x = int(q)
    a = int(r)
    b = int(s)
    if a > b:
        while a < n and x > 0:
            a = a + 1
            x = x - 1
        while b > 1 and x > 0:
            b = b - 1
            x = x - 1
    elif b < a:
        while b < n and x > 0:
            b = b + 1
            x = x - 1
        while a > 1 and x > 0:
            a = a - 1
            x = x - 1
    print(abs(b - a))