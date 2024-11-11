def p(a, b, swap):
    if swap:
        a, b = b, a
    print(a, b)
 
n, m = [int(x) for x in input().split()]
 
if (n == 1 or m == 1) and n * m > 2:
    print(1)
    print(n, m, 1, 1)
    for r in range(n):
        for c in range(m):
            print(r + 1, c + 1)
    print(1, 1)
    exit(0)
 
if n * m % 2 == 0:
    print(0)
    print(1, 1)
    
    swap = m % 2 != 0
    if swap:
        m, n = n, m
 
    for c in range(m):
        for r in range(n - 1):
            if c % 2 == 0:
                p(r + 2, c + 1, swap)
            else:
                p(n - r, c + 1, swap)
    for c in range(m):
        p(1, m - c, swap)
else:
    print(1)
    print(n, m, 1, 1)
    for c in range(m):
        for r in range(n):
            if c % 2 == 0:
                print(r + 1, c + 1)
            else:
                print(n - r, c + 1)
    print(1, 1)