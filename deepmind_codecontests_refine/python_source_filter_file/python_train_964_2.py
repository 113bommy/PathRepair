for _ in range(int(input())):
    n, m = map(int, input().split())
    s = ' ' + input()
    q = s.count('L')
    if q <= m:
        print(max(0, 2 * n - 1))
    elif q == len(s) - 1:
        print(2 * m - 1)
    else:
        x = 0
        y = 0
        C = []
        for i in range(1, len(s)):
            if s[i - 1] == 'W' and s[i] == 'L':
                x = 1
            elif s[i - 1] == 'L' and s[i] == 'L' and x != 0:
                x += 1
            elif s[i] == 'L':
                y += 1
            elif s[i - 1] == 'L' and s[i] == 'W':
                if x != 0:
                    C.append(x)
                x = 0
        if x != 0:
            y += int(x)
        #print(C, y)
        C.sort()
        Ans = 0
        #print(C)
        for i in range(len(C)):
            if m >= C[i]:
                Ans += C[i] * 2 + 1
                m -= C[i]
        #print(Ans)
        Ans += m * 2
        #print(Ans)
        for i in range(1, len(s)):
            if s[i] == 'W':
                if s[i - 1] == 'W':
                    Ans += 2
                else:
                    Ans += 1
        print(Ans)

