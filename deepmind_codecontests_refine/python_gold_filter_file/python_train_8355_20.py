t=int(input())
for i in range(t):
    n,x,y=map(int,input().split())
    n1=n-1
    for i in range(n):
        if (y-x)%n1==0:
            d=(y-x)//n1
            break
        n1-=1
    # print(d)
    z1=x
    z=0
    while z1>0:
        z=z1
        z1-=d
    final=z+(n-1)*d
    # print(z)
    if final<y:
        final=y
    cd=(final-z)//(n-1)
    # print(cd)
    for i in range(n):
        print(final,end=" ")
        final-=d
    print()