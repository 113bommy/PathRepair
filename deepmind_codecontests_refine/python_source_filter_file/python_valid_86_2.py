for _ in range(int(input())):
    ans = 0
    input()
    prev = '2'
    for c, d in zip(input(), input()):
        if c != d:
            ans += 2
            prev = '2'
        else:
            if c == '0':
                ans += 1
            elif c != prev != '2':
                ans += 1
                prev = '2'
            else:
                prev=c
    print(ans)
