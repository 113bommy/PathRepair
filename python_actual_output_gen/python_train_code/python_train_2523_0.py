t=int(input())
for _ in range(t):
    n,a,b=map(int,input().split())
    l=input()
    x=0
    y=2*a
    for i in range(1,n):
        if(l[i]=='1'):
            x=10000000000000000
        c=x
        if(l[i]=='0'):
            x=min(x+a+b,y+2*a+b)
        y=min(c+2*a+2*b,y+a+2*b)
    print(x+a+2*b)