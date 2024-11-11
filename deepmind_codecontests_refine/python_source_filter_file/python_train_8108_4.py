while 1:
    n=int(input())
    if n==0: break
    a=b=0
    while n:
        c,d=map(int,input().split())
        if c<b:b+=c+d
        elif c>d:a+=c+d
        else:
             a+=c
             b+=c
        n-=1
    print(a,b)