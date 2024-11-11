for v in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    for i in range(0,n,2):
        a[i],a[-i-1]=a[-i-1],a[i]
    print(*a)
