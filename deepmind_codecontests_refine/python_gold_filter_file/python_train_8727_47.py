N=int(input())

for n in range(1,3501):
    for h in range(1,3501):
        up,down=N*n*h,4*h*n-N*(h+n)
        if down!=0:
            if up%down==0 and up//down>0:
                print(h,n,(N*n*h)//(4*n*h-N*(h+n)))
                exit()