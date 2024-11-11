t = int(input())
for i in range(t):
    n = int(input())
    sweets = [int(x) for x in input().split()]
    atot = 0
    btot = 0
    atot += sweets[0]
    del sweets[0]
    last = atot
    cnt = 1
    while len(sweets) > 0:
        a = 0
        b = 0
        while b <= last and len(sweets) > 0:
            b += sweets.pop()
        btot += b
        if b > 0:
            cnt += 1

        last = b
        while a <= last and len(sweets) > 0:
            a += sweets.pop(0)
        if a > 0:
            cnt += 1
        last = a
        atot += a
    print(cnt, atot, btot)