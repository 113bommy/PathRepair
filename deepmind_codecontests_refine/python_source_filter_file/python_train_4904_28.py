n = int(input())
if n == 1 or n == 2:
    print("NO")
else:
    print("YES")
    a = 0
    an = []
    b = 0
    bn = []
    if n % 2 == 0:
        k = n // 2
        a = 1
        an.append(k)
        b = n - 1
        for i in range(1, n + 1):
            if i != k:
                bn.append(i)
    else:
        k = (n + 1) // 2
        a = 1
        an.append(k)
        b = n - 1
        for i in range(1, n + 1):
            if i != k:
                bn.append(i)
    print(a, end=' ')
    for i in range(a):
        print(an[i], end=' ')
    print()
    print(b, end=' ')
    for i in range(b):
        print(bn[i], end=' ')
