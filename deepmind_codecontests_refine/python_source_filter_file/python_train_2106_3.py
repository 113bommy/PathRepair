def solv():
    x,initt=map(int,input().split())
    curt=0
    tmin=initt
    tmax=initt
    pos=0
    for n in range(x):
        tm,l,r=map(int,input().split())
        d=tm-curt
        curt=tm
        b=tmax+d
        a=tmin-d
        if b<l or a>r:pos=1

        if l>=a and r<=b:
            tmin=l
            tmax=r
        elif a<l and l<=b and r>=b:
            tmin=l
            tmax=b
        elif l<=a and a<=r and r<b:
            tmin=a
            tmax=r

        elif l<=a and b<=r:
            tmin=max(l,a-d)
            tmax=min(b+d,r)

    print('YNEOS'[pos::2])
        


for _ in range(int(input())):solv()