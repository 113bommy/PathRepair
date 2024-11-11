for _ in range(int(input())):
    m, n = map(int, input().split())
    s = a = b = 0
    ma = 2**32
    for i in range(m):
        x = map(int, input().split())
        for j in x:
            if j < 0:
                a += 1
                s += abs(j)
            else :
                b += 1
                s += abs(j)
            ma = min(ma, abs(j))
    if m%2 != 0:
        s -= ma*2
    print(s)
