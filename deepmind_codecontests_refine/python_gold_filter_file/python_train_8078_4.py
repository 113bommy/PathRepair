n,a,b=map(int,input().split())
t=[]
for i in range(n):
    t.append(list(map(int,input().split())))
m=0
for i in range(n-1):
    for j in range(i+1,n):
        x1,y1=t[i][0],t[i][1]
        x2,y2=t[j][0],t[j][1]
        c=x1+x2
        d=max(y1,y2)
        if c<=a and d<=b:
            if x1*y1+x2*y2>m:
                m=x1*y1+x2*y2
        c=max(x1,x2)
        d=y1+y2
        if c<=a and d<=b:
            if x1*y1+x2*y2>m:
                m=x1*y1+x2*y2
        x2,y2=y2,x2
        c=x1+x2
        d=max(y1,y2)
        if c<=a and d<=b:
            if x1*y1+x2*y2>m:
                m=x1*y1+x2*y2
        c=max(x1,x2)
        d=y1+y2
        if c<=a and d<=b:
            if x1*y1+x2*y2>m:
                m=x1*y1+x2*y2
        x1,y1=y1,x1
        x2,y2=t[j][0],t[j][1]
        c=x1+x2
        d=max(y1,y2)
        if c<=a and d<=b:
            if x1*y1+x2*y2>m:
                m=x1*y1+x2*y2
        c=max(x1,x2)
        d=y1+y2
        if c<=a and d<=b:
            if x1*y1+x2*y2>m:
                m=x1*y1+x2*y2
        x2,y2=y2,x2
        c=x1+x2
        d=max(y1,y2)
        if c<=a and d<=b:
            if x1*y1+x2*y2>m:
                m=x1*y1+x2*y2
        c=max(x1,x2)
        d=y1+y2
        if c<=a and d<=b:
            if x1*y1+x2*y2>m:
                m=x1*y1+x2*y2
print(m)