t = int(input())

ns = []

for i in range(t):

    n, te = map(int, input().split())

    arr = list(map(int, input().split()))

    color = []
    c = set()

    if te % 2 != 0:
        for el in arr:
            if (te - el) not in c:
                color.append(0)
                c.add(el)
            else:
                color.append(1)
    else:
        num = arr.count(te // 2)
        ctr = 0
        for el in arr:
            if el == te // 2:
                if ctr > num // 2:
                    color.append(1)
                else:
                    color.append(0)
                ctr += 1
            elif (te - el) not in c:
                color.append(0)
                c.add(el)
            else:
                color.append(1)

    ns.append(color)


for el in ns:
    print(" ".join(list(map(str, el))))