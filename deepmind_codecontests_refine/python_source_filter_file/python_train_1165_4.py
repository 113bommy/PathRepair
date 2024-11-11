for _ in range(int(input())):
    s = input()
    o = []
    e = []
    for i in s:
        if int(i) % 2 == 0:
            e.append(i)
        else:
            o.append(i)
    ans = []
    x = 0
    y = 0
    while len(e) > x and len(o) > y:
        if int(o[0]) > int(e[0]):
            ans.append(e[0])
            x += 1
        else:
            ans.append(o[0])
            y += 1
    print(''.join(ans + o[y:] + e[x:]))