for tc in [0]*int(input()):
    n=int(input())
    l=list(map(int,input().split()))
    x=l[0]
    for i in l[1::]:
        x=x^i
    xx=sum(l)
    if 2*x==xx:
        print(0)
        print()
    else:
        print(2)
        print(xx,xx+x)
     