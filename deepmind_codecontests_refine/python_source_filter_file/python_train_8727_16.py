N = int(input())
for h in range(1,3501):
    for n in range(1,3501):
        if (4*h*n-N*h-N*n)>0 and (h*n)%(4*h*n-N*h-N*n)==0:
            print(h,n,h*n//(4*h*n-N*h-N*n))
            exit()