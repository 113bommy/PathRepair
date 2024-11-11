m, n = [int(n) for n in input().split()]
size = m*n
if 1<=m<=n<=16:
    if size % 2 == 0:
        print(size)
    elif size%2 !=0:
        print(int((size-1)/2))



