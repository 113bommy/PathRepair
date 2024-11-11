t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    d={}
    for i in a:
        if i in d:
            d[i]+=1
        else:
            d[i]=1
    x=len(d)
    same=0
    for i in d.values():
        if i>same:
            same=i
    un=x-1
    if un==0:
        print(0)
    elif same==1:
        print(1)
    elif same<=un:
        print(same)
    else:
        if same-un>=2:
            print(un+1)
        else:
            print(un)
        