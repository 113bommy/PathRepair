N = int(input())
for h in range(1, 3501):
    for n in range(1, 3501):
        waru = 4 * h * n - N * n - N * h
        if waru > 0 and (N * h * n) % waru == 0:
                print("{} {} {}".format(h, n, (N * h * n) // waru))
                exit()