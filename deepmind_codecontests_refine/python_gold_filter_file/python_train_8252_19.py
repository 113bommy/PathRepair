for s in [*open(0)][1:]:
    n = int(s)
    print(n)
    a = [ i for i in range(1,n+1)]
    print(*a[0::])