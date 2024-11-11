n,a,b,k= map(int,input().split())
l=list(map(int,input().split()))
count_a=0
count_b=0
z=list()

for i in range(n):
    m=l[i]
    m=m%(a+b)
    if m==0:
        count_b+=1
        if b>a:
            if b%a==0:
                z.append(b//a) #correct
            elif b%a!=0:
                z.append((b//a)+1) #correct till here
        elif a>=b:
            z.append(1)
    elif m-a>0:
        count_b+=1
        m=m-a
        c=m%a
        if c==0:
            z.append(m//a) #correct
        elif c!=0:
            z.append((m//a)+1) #√
    elif m-a<=0:
        count_a+=1
z.sort()

if len(z)==0:
    print(count_a)
else:
    if z[0]>k:
        g=0
    elif z[0]==k:
        g=1
    elif sum(z)<k:
        g=len(z)
    else:
        d = 0
        for i in range(len(z)):
            d+=z[i]
            if d>k:
                g=i
                break

    print(count_a+g)
