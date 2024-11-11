for _ in range(int(input())):
    n,h=map(int,input().split())
    a=[*map(int,input().split())]
    def s(k):
        s=k
        for i in range(n-1):
            s+=min(k,a[i+1]-a[i])
        return s
    d=0
    f=h
    while f>d:
        m=(f+d)//2
        if s(m)>h:
            f=m
        else:
            d=m+1
    print(d)