N = int(input())
for h in range(1, 3501):
    for n in range(1, 3501):
        bunshi = N * h * n
        bunbo = 4 * h * n - N * n - N * h
        if bunbo > 0 and bunshi % bunbo == 0:
            print("{} {} {}".format(h, n, bunshi // bunbo))
            exit()