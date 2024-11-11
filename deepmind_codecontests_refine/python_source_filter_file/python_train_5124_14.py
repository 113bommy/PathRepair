t = int(input())
for i in range(t):
    input()
    s = input()
    try:
        s = s[s.index('A')::]
    except:
        print(0)
        continue

    n, m, a = 0, 0, True
    for x in s:
        if a:
            if x == 'P':
                n -=- 1
            else:
                a = False
                if n > m:
                    m = n
        else:
            if x == 'P':
                a = True
                n = 1

    print(n)
