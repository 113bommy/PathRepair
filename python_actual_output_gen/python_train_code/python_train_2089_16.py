for t in range(int(input())):
    n,m=map(int,input().split())
    x=[int(f) for f in input().split()]
    b=sum(x[1:])
    if  b>m:
        print(m+1)
    else:
        print(x[0]+b)