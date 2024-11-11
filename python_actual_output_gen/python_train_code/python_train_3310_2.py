t = int(input())
for i in range(t):
    a, b, c, d = map(int, input().split())
    ov = b
    a -= b
    if a > 0 and d >= c:
        print(-1)
    else:
        if b >= a:
            print(b)
        else:
            if a % (c - d) == 0:
                ov += (c * (a // (c - d)))
            else:
                ov += (c * (a // (c - d) + 1))
            print(ov)
