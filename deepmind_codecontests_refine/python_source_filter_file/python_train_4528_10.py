i = int(input())
v = sorted(list(map(int, input().split())))
tl = 0
tc = 0
for value in range(0, i):
    test = v[value]
    e = 0
    while e == 0:
        if test == tl:
            tc += 1
            test += 1
        else:
            tl = test
            e = 1

print(tc)
