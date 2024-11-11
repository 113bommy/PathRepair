N = int(input())
for h in range(1, 3501):
    for n in range(1, 3501):
        bunbo = 4 * h * n - N * n - N * h
        if bunbo > 0 and N * h * n % bunbo == 0:
            print("{} {} {}".format(h, n, N * h * n // bunbo))
            exit()