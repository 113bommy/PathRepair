for i in range(int(input())):
    s, t = input(), input()
    q = False
    for e in s:
        if e in t:
            q = True
        break
    print('NO') if not q else print('YES')

