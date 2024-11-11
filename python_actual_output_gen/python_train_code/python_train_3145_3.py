while True:
    try:
        s = input()
        l = list(map(int, input().split(' ')))
        if len(l) == len(set(l)):
            print(s)
            continue
        m = 0
        for i in l:
            m = max(m, l.count(i))
        if m == 1:
            print(s)
        else:
            print(m)
    except:
        break