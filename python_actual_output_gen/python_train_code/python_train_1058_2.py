for i in range(int(input())):
    n,m = list(map(int,input().split()))
    x = n | m
    print((n^x) + (m^x), "x :",x)
