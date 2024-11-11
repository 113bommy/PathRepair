def check(v):
    d=v[1][0]-v[0][0]
    for i in range(1,len(v)):
        if v[i][0]-v[i-1][0]!=d:
            return False
    return True
n=int(input())
a=sorted(zip(map(int,input().split()),range(n)))
if n<3:
    print(1)
else:
    if check(a):
        print(a[0][1]+1)
    elif check(a[1:]):
        print(a[0][1]+1)
    elif check(a[:-1]):
        print(a[-1][1]+1)
    else:
        d=a[-1][0]-a[0][0]
        if d%(n-2):
            print(-1)
        else:
            d//=n-2
            b=[]
            x=a[0][0]
            for i in range(1,n):
                if a[i][0]-x!=d:
                    b+=a[i][1]+1,
                else:
                    x=a[i][0]
            if len(b)>1:
                print(-1)
            else:
                print(b[0])
