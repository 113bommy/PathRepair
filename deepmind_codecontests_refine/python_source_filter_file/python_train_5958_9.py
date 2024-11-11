for i in range(int(input())):
    n, g, b = list(map(int, input().split()))
    d = g
    n2 = n // 2 + (1 if n % 2 == 1 else 0)
    n2 -= g
    k = n2 // g + (1 if n % g != 0 else 0)
    d += b * k
    d += n2
    print(max(d, n))
