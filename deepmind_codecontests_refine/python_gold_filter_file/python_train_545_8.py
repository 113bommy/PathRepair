n=int(input())
a=list(map(int,input().split()))
if(n>2):
    print(1,1)
    print(-(a[0]))
    a[0]=0
    print(2,n)
    for i in a[1:n]:
        print((i*(n-1)),end=' ')
    print()
    print(1,n)
    for i in a:
        print(-(i*n),end=' ')
else:
    if(n==1):
        print(1,1)
        print(-a[0])
        for i in range(2):
            print(1,1)
            print(0)
    else:
        print(1,1)
        print(-a[0])
        print(2,2)
        print(-a[1])
        print(1,1)
        print(0)
    
    
