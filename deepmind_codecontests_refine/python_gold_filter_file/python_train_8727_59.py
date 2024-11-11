N = int(input())

for h in range(1, 3501):
    for n in range(1, 3501):
        v = 4 * h * n - N * n - N * h
        if v == 0:
            continue
        w = (N * h * n) / v
        if w.is_integer() and w > 0:
            print(h, n, int(w))
            quit()