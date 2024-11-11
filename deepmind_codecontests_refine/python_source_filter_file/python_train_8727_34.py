N = int(input())
for h in range(1, 3501):
    for n in range(1, 3501):
        a = n * h + N
        b = 4 * h * n - N * n - N * h
        if b > 0 and a % b == 0:
            print(h, n, a // b)
            quit()
assert(False)
