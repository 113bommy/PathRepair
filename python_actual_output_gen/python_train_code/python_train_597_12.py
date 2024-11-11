for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    gre=a[-1]
    tot=0
    for i in range(n-1,-1,-1):
        if a[i]>=gre:
            tot+=1
        gre=min(gre,a[i])
        # print(gre,tot)
    print(tot)