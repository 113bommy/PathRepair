n=int(input())
a=list(map(int,input().strip().split()))
b=0
c=0
d=0
e=0
if a[0]!=25:
    print('NO')
else:    
    for i in range(n):
        if a[i]==25:
            b=b+1
        elif a[i]==50:
            c=c+1
            b=b-1
        elif a[i]==100:
            d=d+1
            if c>0:
                c=c-1
                d=d-1
            else:
                b=b-3
        if c<0 or b<0 or d<0:
            e=1
            break
    if e==0:
        print('YES')
    if e==1:
        print('NO')