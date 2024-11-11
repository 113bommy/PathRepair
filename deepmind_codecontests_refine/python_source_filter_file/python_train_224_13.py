for i in range(int(input())):
    r = list()
    l = list()
    for i in range(int(input())):
        s = input().split()
        l.append(int(s[0]))
        r.append(int(s[1]))
    a = ((min(r) - max(l)) ** 2) ** 0.5
    if min(r) >= max(l):
        a = 1
    print(int(a))