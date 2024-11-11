N = int(input())

for n in range(1, 3501):
    for w in range(n, 3501):
        t = 4 * n * w - N * w - N * n
        if t > 0:
            h = N * n * w / t
            if h.is_integer() and h > 0:
                print(int(h), n, w)
                exit()
