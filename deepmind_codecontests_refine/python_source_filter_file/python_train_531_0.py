n,k=list(map(int,input().split()))
a=list(map(int,input().split()))
b=[-1]*k
for m in a:
    c=[-1]
    for x in range(1,k+1):
        j=x-1
        if b[j]==-1:
            yl=k//2+1-m//2
            yr=yl+m-1
            d=abs(x-k//2-1)*m+(2*(k//2+1)-(yl+min(yr,k//2+1)))*max(0,min(yr,k//2+1)-yl+1)//2+((max(k//2+2,yl)+yr)-2*(k//2+1))*max(0,yr-max(k//2+1,yl)+1)//2
            x1,yl1,yr1=x,yl,yr
            if c!=[-1]:
                x,yl,yr=c
            if c==[-1] or d<abs(x-k//2-1)*m+(2*(k//2+1)-(yl+min(yr,k//2+1)))*max(0,min(yr,k//2+1)-yl+1)//2+((max(k//2+2,yl)+yr)-2*(k//2+1))*max(0,yr-max(k//2+1,yl)+1)//2:
                c=[x1,yl1,yr1]
        else:
            if b[j][0]>m:
                yl=b[j][0]-m
                yr=yl+m-1
                d=abs(x-k//2-1)*m+(2*(k//2+1)-(yl+min(yr,k//2+1)))*max(0,min(yr,k//2+1)-yl+1)//2+((max(k//2+2,yl)+yr)-2*(k//2+1))*max(0,yr-max(k//2+1,yl)+1)//2
                x1,yl1,yr1=x,yl,yr
                if c!=[-1]:
                    x,yl,yr=c
                if c==[-1] or d<abs(x-k//2-1)*m+(2*(k//2+1)-(yl+min(yr,k//2+1)))*max(0,min(yr,k//2+1)-yl+1)//2+((max(k//2+2,yl)+yr)-2*(k//2+1))*max(0,yr-max(k//2+1,yl)+1)//2:
                    c=[x1,yl1,yr1]
                x=x1
            if k-b[j][1]>=m:
                yl=b[j][1]+1
                yr=yl+m-1
                d=abs(x-k//2-1)*m+(2*(k//2+1)-(yl+min(yr,k//2+1)))*max(0,min(yr,k//2+1)-yl+1)//2+((max(k//2+2,yl)+yr)-2*(k//2+1))*max(0,yr-max(k//2+1,yl)+1)//2
                x1,yl1,yr1=x,yl,yr
                if c!=[-1]:
                    x,yl,yr=c
                if c==[-1] or d<abs(x-k//2-1)*m+(2*(k//2+1)-(yl+min(yr,k//2+1)))*max(0,min(yr,k//2+1)-yl+1)//2+((max(k//2+2,yl)+yr)-2*(k//2+1))*max(0,yr-max(k//2+1,yl)+1)//2:
                    c=[x1,yl1,yr1]
    print(*c)
    if c!=[-1]:
        if b[c[0]-1]==-1:
            b[c[0]-1]=c[1:]
        else:
            b[c[0]-1][1]=max(b[c[0]-1][1],c[2])
            b[c[0]-1][0]=min(b[c[0]-1][0],c[1])