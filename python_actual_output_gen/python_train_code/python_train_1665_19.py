t = int(input())
for _ in range(t):
    a, b, c = tuple(int(i) for i in input().split(' '))
    aCopy, bCopy, cCopy = a, b, c
    m = 30000
    for x in range(1, 10000):
        for y in range(x, 10000, x):
            for z in range(y, 10000, y):
                if m > abs(a - x) + abs(b - y) + abs(c - z):
                    m = abs(a - x) + abs(b - y) + abs(c - z)
                    aCopy = x
                    bCopy = y
                    cCopy = z

    print(m)
    print(aCopy, bCopy, cCopy)