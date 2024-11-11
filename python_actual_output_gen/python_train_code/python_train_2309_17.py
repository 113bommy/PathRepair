t=int(input())
for _ in range(t):
    n,a,b=map(int,input().split())
    if(n%2==0):
        if(a*2<b):
            print(n*a)
        else:
            print((n//2)*b)
    else:
        c=a
        if(a*2<b):
            print(c+n*a)
        else:
            print(c+(n//2)*b)