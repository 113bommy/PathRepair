for _ in range(int(input())):
    n = int(input())
    data = list(map(int, input().split()))

    a = data[0]
    apoint = 1
    b = 0
    bpoint = n-1
    ac = data[0]
    bc = 0
    moves = 1

    achance = True
    i = 1
    while i < n:
        if(achance == True):
            b = 0
            f = 0
            while b <= a and i < n:

                b += data[bpoint]
                bpoint -= 1
                f = 1
                i += 1
            bc += b
            if(f == 1):
                moves += 1
            achance = not achance
        else:
            a = 0
            f = 0
            while a <= b and i < n:

                a += data[apoint]
                apoint += 1
                f = 1
                i += 1
            ac += a
            if(f == 1):
                moves += 1
            achance = not achance

    # print("aaaaaaaaaaaaaa")
    print(moves, ac, bc)
