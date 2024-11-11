for _ in range(int(input())):
    a, b, c, m = map(int, input().split())
    
    c, b, a = sorted([a, b, c])

    a -= 1
    b -= 1
    c -= 1

    if a - b >= m:
        a -= m
        m = 0
    else:
        m -= (a - b)
        a = b

        if (a - c) * 2 >= m:
            a -= (m // 2)
            b -= (m // 2 + m % 2)
            m = 0
        else:
            m -= (a - c) * 2
            a = c
            b = c
        
            if (a + b + c) >= m:
                now = (m // 3)
                a -= now
                m -= now

                now = (m // 2)
                b -= now
                m -= now

                now = m
                c -= now
                m -= now

    li = [a, b, c]
    li = sorted(li)

    # print(li, m)

    if m > 0:
        print("NO")
    elif (li[0] + li[1] + 2) >= li[2]:
        print("YES")
    else:
        print("NO")