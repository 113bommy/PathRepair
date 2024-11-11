t=int(input())
for i in range(t):
    n=int(input())
    s=list(map(int,input().split()))
    zero=0
    one=0
    for i in range(n):
        if s[i]==1:
            one+=1
        else:
            zero+=1
    if zero>=one:
        print(zero)
        for i in range(zero):
            print(0,end=" ")
        print("\t")
    else:
        if one%2==0:
            one-=1
        print(one)
        for i in range(one):
            print(1,end=" ")
        print("\t")