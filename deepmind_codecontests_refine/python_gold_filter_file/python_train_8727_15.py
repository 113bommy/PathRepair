N = int(input())
for h in range(1, 3501):
    for n in range(1, 3501):
        if 4*h*n-N*n-N*h!=0:
            w = N*h*n/(4*h*n-N*n-N*h)
            if w == int(w) and w >= 1:
                print(h, n, int(w))
                exit()
