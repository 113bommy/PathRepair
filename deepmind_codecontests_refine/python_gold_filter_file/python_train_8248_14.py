for _ in range(int(input())):
    n = int(input())
    a = sorted([*map(int, input().split())])
    f = False
    for i in range(1, a[-1]*2):
        tmp = []
        for j in a:
            if j not in tmp:
                tmp.append(j)
                j^=i
                tmp.append(j)
        if set(tmp) == set(a):
            f = True
            break
    if f:
        print(i)
    else:
        print(-1)