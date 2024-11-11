import sys
input = sys.stdin.readline
for f in range(int(input())):
    n,k=map(int,input().split())
    l1,r1=map(int,input().split())
    l2,r2=map(int,input().split())
    intersect=False
    if l1>=l2 and l1<=r2:
        intersect=True
    if r1>=l2 and r1<=r2:
        intersect=True
    if l2>=l1 and l2<=r1:
        intersect=True
    if r2>=l1 and r2<=r1:
        intersect=True
    if intersect:
        l=min(l1,l2)
        r=max(r1,r2)
        totlen=r-l
        intlen=(r2-l2)+(r1-l1)-totlen
        if n*intlen>=k:
            print(0)
        else:
            if n*totlen>=k:
                print(k-n*intlen)
            else:
                s=n*(totlen-intlen)
                k-=n*totlen
                print(s+2*totlen)
    else:
        l=min(l1,l2)
        r=max(r1,r2)
        totlen=r-l
        dist=totlen-(r2-l2)-(r1-l1)
        s=0
        i=0
        while k>0 and i<n:
            i+=1
            s+=dist
            if k<=totlen:
                s+=k
                k=0
            else:
                k-=totlen
                s+=totlen
                if k<dist:
                    s+=2*k
                    k=0
        if k>0:
            s+=2*k
        print(s)