for i in range(int(input())):
    s, t = input(), input()
    f = 0
    for j in set(s):
        if j in set(t):
            f = 1
            break
    print(['YES', 'NO'][f])
