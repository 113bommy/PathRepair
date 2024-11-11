import sys
N = int(input())
for h in range(1,3501):
    for n in range(1,3501):
        tmp = 4*h*n-N*(n+h)
        if tmp == 0:
            continue
        d,m = divmod(N*h*n, tmp)
        if m == 0 and d > 0:
            print(h,n,d)
            sys.exit()