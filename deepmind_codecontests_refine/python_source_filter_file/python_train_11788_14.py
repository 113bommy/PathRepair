x = int(input())
t = []
for c in range(x):
    v = input()
    vv =[]
    for cc in range(len(v)):
        vv.append(v[cc])
    t.append(vv)


for c in t:
    zero = 0
    for cc in range(len(c)):
        zero + int(c[cc])
    if zero == 0:
        print("0")
    else:
        win = 0
        countL = 0
        countR = len(c)
        reverse = -1
        while c[countL] != "1":
            countL = countL +1

        while c[reverse] != "1":
            reverse = reverse-1
            countR = countR-1

        win = 0
        for x in range(countL,countR):
            if c[x] == "0":
                win = win + 1
        print(win)

