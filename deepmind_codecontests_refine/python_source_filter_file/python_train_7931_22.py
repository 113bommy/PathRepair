for _ in range(int(input())):    
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    if n==1:
        print(1)
        exit()
    f=0
    for i in range(n-1):
        if a[i+1]-a[i]==1:
            f=1
            break
    if f:
        print(2)
    else:
        print(1)