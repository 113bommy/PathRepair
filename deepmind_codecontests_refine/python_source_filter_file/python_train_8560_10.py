for i in range(int(input())):
    h, m, n = map(int, input().split())
    while h > 0 and m + n > 0:
        if m > 0:
            q1 = h // 2 + 10
        else:
            q1 = h
        if n > 0:
            q2 = h-10
        else:
            q2 = h
        if q1 > q2:
            h = q2
            m -= 1
        else:
            h = q1
            n-=1
    if h < 1:
        print("YES")
    else:
        print("NO")
