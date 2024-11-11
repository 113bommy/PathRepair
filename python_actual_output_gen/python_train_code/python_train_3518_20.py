for _ in range(int(input())):
    a,b,n=map(int,input().split())
    if a>b: a,b=b,a
    c=0
    while (a<=n) and (b<=n):
        if c%2==0: b=a+b
        else: a=a+b
        c+=1
    print(c)