N=int(input())
table=[]
for i in range(N):
    x,y,d=input().split()
    x,y=int(x),int(y)
    table.append((x,y,d))
anspos=[0]
inf=10**10
a=-inf
b=-inf
c=-inf
for i in range(N):
    x,y,d=table[i]
    if d=='L':
        a=max(x,a)
    elif d=='R':
        b = max(x, b)
    else:
        c = max(x, c)
#anspos+=[(a+b)/2,(b+c)/2,(c+a)/2]
#anspos+=[max( (a-b)/2,0),max((b-a)/2,0),max(c-a,0),max(a-c,0),max(abs(b-c),0),max(c-b,0)]
anspos+=[abs(a-b)/2,abs(a-c),abs(b-c)]
a=inf
b=inf
c=inf
for i in range(N):
    x,y,d=table[i]
    if d=='L':
        a=min(x,a)
    elif d=='R':
        b = min(x, b)
    else:
        c = min(x, c)
anspos+=[abs(a-b)/2,abs(a-c),abs(b-c)]
a=-inf
b=-inf
c=-inf
for i in range(N):
    x,y,d=table[i]
    if d=='U':
        a=max(y,a)
    elif d=='D':
        b = max(y, b)
    else:
        c = max(y, c)
anspos+=[abs(a-b)/2,abs(a-c),abs(b-c)]
a=inf
b=inf
c=inf
for i in range(N):
    x,y,d=table[i]
    if d=='D':
        a=min(y,a)
    elif d=='U':
        b = min(y, b)
    else:
        c = min(y, c)
ans=10**30
anspos+=[abs(a-b)/2,abs(a-c),abs(b-c)]
#print(anspos)
for t in anspos:
    xmax=-inf
    xmin=inf
    ymax=-inf
    ymin=inf
    for i in range(N):
        x, y, d = table[i]
        if d=='U':
            y+=t
        elif d=='D':
            y-=t
        elif d=='L':
            x-=t
        elif d=='R':
            x+=t
        xmax=max(xmax,x)
        xmin = min(xmin, x)
        ymax = max(ymax, y)
        ymin = min(ymin, y)
    kai=(xmax-xmin)*(ymax-ymin)
    #print(kai,t)
    ans=min(ans,kai)
print(ans)
