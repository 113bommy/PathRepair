for _ in range(int(input())):
    # n = input()
    n = int(input())
    # n, k = map(int, input().split())
    l = list(map(int, input().split()))
    al = 0
    ar = 0
    bl = 0
    br = 0
    ar += l[0]
    i = 1
    j = n - 1
    c = 1
    d = 0
    while i <= j:

        br = bl

        d = j

        while (bl - br) <= (ar - al):
            bl += l[j]
            if d == j:
                c += 1
            #print("bl:", bl, j, c)
            j -= 1
            if i > j:
                break
        al = ar
        if i > j:
            break
        d = i
        while (ar - al) <= (bl - br):
            ar += l[i]
            if d == i:
                c += 1
            #print("ar:", ar, i, c)
            i += 1
            if i > j:
                break
    print(c, ar, bl)
