for i in range(int(input())):
    n,k=list(map(int,input().split()))
    l=list(map(int,input().split()))
    if len(l)%2!=0:
        z = max(l)
        l=[z-i for i in l]
    else:
        for j in range (2):
            z = max(l)
            for i in range (len(l)):
                l[i]=(z-l[i])
    print(*l)