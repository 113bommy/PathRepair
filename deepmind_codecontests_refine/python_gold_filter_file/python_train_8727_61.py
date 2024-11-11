N = int(input())
for h in range(1,3501):
    for n in range(1,3501):
        d = 4*h*n-N*h-N*n
        if d == 0 or N*h*n%d != 0: continue
        w = N*h*n//d
        if w < 0: continue
        print(h,n,w)
        exit()