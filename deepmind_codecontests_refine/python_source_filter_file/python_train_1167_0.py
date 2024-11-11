for i in range(int(input())):
    l = []
    for j in range(int(input())):
        l.append(list(map(int, input().split())))
    x, y = (0, 0)
    l.sort(key=lambda x: x[0] + x[1])
    s = []
    prev = (0, 0)
    abort = False
    for i in l:
        if prev[0] > i[0] or prev[1] > i[1]:
            abort = True
            break
        else:
            s.append('R' * (i[0] - prev[0]))
            s.append('U' * (i[1] - prev[0]))
        prev = i.copy()
    if not abort:
        print('YES')
        print(*s, sep='')
    else:
        print('NO')
