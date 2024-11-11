for _ in range(int(input())):
    a,b,c,r=map(int,input().split())
    if a>b:
        a,b=b,a
    p=c-r
    q=c+r
    if p<=a and b<=q:
        print(0)
    elif a<p and b>q:
        print(abs(a-b)-abs(p-q))
    elif (a<p and b<p) or (a>q and b>q):
        print(abs(a-b))
    elif a<p:
        print(abs(a-p))
    else:
        print(abs(q-b))