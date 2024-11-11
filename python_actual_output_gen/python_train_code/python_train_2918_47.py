a,b=map(int,input().strip().split())
if a==b:
    print(a,"0")
elif a>b:
    if (a-b)%2==0:
        pass
    else:
        a=(a-b)-1
    print(b,a//2)
else:
    if (b-a)%2==0:
        pass
    else:
        b=(b-a)-1
    print(a,b//2)