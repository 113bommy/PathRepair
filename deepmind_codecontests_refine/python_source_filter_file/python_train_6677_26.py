for _ in range(int(input())):
    n,a,b=map(int,input().split())
    if(a*2>b):
        t=n//2
        s=t*b+a
    else:
        s=a*n
    print(s)