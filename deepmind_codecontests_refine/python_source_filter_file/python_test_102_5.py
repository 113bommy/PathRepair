for q in range(int(input())):
    str, stb = input().split()
    str = int(str)
    stb = int(stb)
    naprav = list(input())
    l = 0
    r = 0
    u = 0
    d = 0
    lr = 0
    ud = 0
    z = 0
    for i in range(len(naprav)):
        if naprav[i] == "L":
            lr -= 1
        elif naprav[i] == "R":
            lr += 1
        elif naprav[i] == "D":
            ud -= 1
        elif naprav[i] == "U":
            ud += 1
        if lr - l >= stb or r - lr >= stb or ud - d >= str or u - ud >= str:
            print(1 + u, 1 - l)
            z = 1
            break
        elif lr < l:
            l = lr
        elif lr > r:
            r = lr
        elif ud < d:
            d = ud
        elif ud > u:
            u = ud
    if z == 0:
        print(1 - d, 1-l)