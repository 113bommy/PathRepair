t = list(map(int, input().split()))
tset = list(set(t))
t.sort()
if len(tset) == 1:
    print(tset[0] * 2)
elif len(tset) == 2:
    if t.count(tset[0]) == 1 or t.count(tset[0]) == 4:
        print(t[0] + t[1])
    else:
        print(min(t.count(tset[0]) * tset[0], t.count(tset[1]) * tset[1]))
elif len(tset) == 3:
    for i in range(3):
        if t.count(tset[i]) == 3:
            print(sum(t) - 3 * tset[i])
            exit()
    else:
        t.sort()
        if t.count(max(t)) == 1:
            print(sum(t) - 2 * t[3])
        else:
            print(sum(t) - 2 * t[4])
        exit()
elif len(tset) == 4:
    for i in range(4):
        if t.count(tset[i]) == 2:
            print(sum(t) - 2 * tset[i])
            exit()
else:
    print(sum(t))
