t = int(input())
for t0 in range(t):
    a, b, c, d = map(int, input().split())
    if b < a:
        s = b
        if d >= c:
             print(-1)
        else:
            n = (a - b) // (c - d)
            if (a - b) % (c - d) != 0:
                n += 1
            s += n * c
            print(s)
    else:
        print(b)
