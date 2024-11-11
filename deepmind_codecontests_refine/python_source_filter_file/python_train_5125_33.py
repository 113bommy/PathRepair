for i in range(int(input())):
    n,d=map(int,input().split())
    l=[int(i) for i in input().split()][:n]
    for j in range(1,len(l)):
        if(l[j]*j<=d):
            l[0]+=l[j]
            d=d-l[j]
        else:
            h=d//j
            l[0]+=h
            break
    print(l[0])
