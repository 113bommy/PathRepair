N = int(input())

for h in range(1,3501):
    for n in range(h,3501):
        wd = 4*h*n - n*N - h*N
        wu = N*h*n
        if wd > 0 and wu % wd == 0:
            w = wu // wd
            print(h,n,w)
            exit()
