p,d=list(map(int,input().split()))
c=max(len(str(d)),1)
while c>0:
    a=p%(10**c)
    if a+1>d:
        c=c-1
    else:
        if (p-(a+1))%10**c!=a:
            p=p-(a+1)
        c=-1
        break
print(p)