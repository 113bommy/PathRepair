t, m = [int(i) for i in input().split()]
a = []
k = 0
for i in range(t):
    # print(a)
    f = True
    op = input()
    if op[:5] == "alloc":
        j, b = op.split()
        b = int(b)
        s = 0
        for j in range(len(a)):
            if a[j][1] - s > b:
                k += 1
                a.insert(j, (k, s, b))
                print(k)
                f = False
                break
            else:
                s = a[j][1] + a[j][2]
        if f:
            if m - s > b:
                k += 1
                a.append((k, s, b))
                print(k)
                continue
            else:
                print("NULL")
    elif op[:5] == "erase":
        j, b = op.split()
        b = int(b)
        for j in a:
            if j[0] == b:
                a.remove(j)
                f = False
                break
        if f:
            print("ILLEGAL_ERASE_ARGUMENT")
    else:
        s = 0
        for j in range(len(a)):
            a[j] = (a[j][0], s, a[j][2])
            s += a[j][2]
