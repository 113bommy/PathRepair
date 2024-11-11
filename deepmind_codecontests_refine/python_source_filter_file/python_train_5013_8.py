t = int(input())
c = 26
for _ in range(t):
    s = list(input())
    s.sort()
    n = len(s)
    u = [0] * c
    for i in range(n):
        u[ord(s[i]) - ord('a')] += 1
    w = 0
    d = []
    p = []
    for i in range(c):
        if u[i] != 0:
            w += 1
            d.append(chr(i + ord('a')))
            p.append(u[i])
    if w > 4:
        for i in range(w // 2):
            r = (w - 1) // 2 + 1
            print(d[i] * p[i] + d[i + r] * p[i + r], end = '')
        if w % 2 == 1:
            print(d[w // 2] * p[w // 2], end = '')
        print()
    elif w == 4:
        print(d[2] * p[2] + d[0] * p[0] + d[3] * p[3] + d[1] * p[1])
    elif w == 1:
        print(d[0] * p[0])
    elif w == 2:
        if abs(ord(d[0]) - ord(d[1])) == 1:
            print('No answer')
        else:
            print(d[0] * p[0] + d[1] * p[1])
    else:
        if ord(d[1]) - ord(d[0]) == 1 and ord(d[2]) - ord(d[1]) == 1:
            print('No answer')
        else:
            if ord(d[1]) - ord(d[0]) > 1:
                print(d[0] * p[0] + d[1] * p[1] + d[2] * p[2])
            else:
                print(d[0] * p[0] + d[2] * p[2] + d[1] * p[1])
