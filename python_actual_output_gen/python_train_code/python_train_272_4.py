for _ in range(int(input())):
    n,k=map(int,input().split())
    lis=list(map(int,input().split()))
    gr=max(lis)
    while k>0:
        ma=gr
        ini=0
        for i in range(n):
            lis[i]=ma-lis[i]
            if lis[i]>=ini:
                ini=lis[i]
                gr=ini
        k-=1
        if gr==ma:
            break
        elif gr==0:
            break
    if gr==0:
        print("0"*n)
    else:
        if k%2==0:
            print(*lis)
        else:
            for i in lis:
                if i==gr:
                    print(0,end=" ")
                elif i==0:
                    print(gr,end=" ")
                else:
                    print(gr-i,end=" ")
            print()