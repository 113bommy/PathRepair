for _ in range(int(input())):
    n,k=map(int,input().split())
    l=int(k/(n-1))
    if k%(n-1)==0:
        print(int(k/(n-1)*n)-1)
    else:
        print(int(k/(n-1)*n)+k%(n-1))