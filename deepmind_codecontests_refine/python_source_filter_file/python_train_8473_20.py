n = int(input())
l = list(map(int, input().split()))
s = set(l)
if len(s) < 3 or 5 in l or 7 in l:
    print(-1)
else:
    d = {1: 0, 2: 0, 3: 0, 4: 0, 6: 0}
    for i in l:
        d[i] = d.get(i, 0) + 1
    if 6 in s and 4 in s:
        if d[1] == (d[6]+d[4]):
            c = d[6] - d[3]
            rem = d[2] - c
            if rem <= 0:
                print(-1)
            else:
                if rem != d[4]:
                    print(-1)
                else:
                    for i in range(rem):
                        print(1, 2, 4)
                    for i in range(d[3]):
                        print(1, 3, 6)
                    for i in range(d[2] - rem):
                        print(1, 2, 6)
        else:
            print(-1)
    else:
        if 6 in d:
            if d[1] == d[6]:
                if d[2] + d[3] == d[6]:
                    for i in range(d[3]):
                        print(1, 3, 6)
                    for i in range(d[6]-d[3]):
                        print(1, 2, 6)
                else:
                    print(-1)
            else:
                print(-1)
        elif 4 in d:
            if d[1] == d[4] and d[2] == d[4]:
                for i in range(d[2]):
                    print(1, 2, 4)
            else:
                print(-1)
        else:
            print(-1)
