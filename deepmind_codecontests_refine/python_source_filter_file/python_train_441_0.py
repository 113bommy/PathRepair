for query in range(int(input())):
    n=int(input())
    a=[int(x) for x in input().split()]
    b=[int(x) for x in input().split()]
    c=[int(x) for x in input().split()]
    y=a[0]
    print(y, end=" ")
    for z in range(1,n-1):
        if a[z]!=y:
            y=a[z]
            print(y, end=" ")
            continue
        y=b[z]
        print(y,end=" ")
    if a[n-1]!=y and a[n-1]!=a[0]:
        print(a[n-1])
        continue
    if b[n-1]!=y and b[n-1]!=b[0]:
        print(b[n-1])
        continue
    print(c[n-1])
