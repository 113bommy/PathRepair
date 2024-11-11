for _ in range(int(input())):
    n,d=map(int,input().split())
    p=list(map(int,input().split()))
    while d>0:
        for i in range(1,n-1):
            if p[i]>0:
                p[i]=p[i]-1
                p[i-1]=p[i-1]+1
                break;
        d=d-1
    print(p[0])