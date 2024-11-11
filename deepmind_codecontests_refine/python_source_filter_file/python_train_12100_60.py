for i in range(int(input())):
    s0, p0, s1, p1 = map(int, input().split())
    if (s1 - s0) % (p0 + p1):
        print(-1)
    else:
        print((s1 - s0) // (p0 + p1))