t,m=input().split()
t,m=int(t),int(m)
d={i:-1 for i in range(t+1)}
s={i:-1 for i in range(t+1)}
b=[0]*m
l=[]
r=1
for i in range(t):
    c=input().split()
    if c[0]=='alloc':
        k=int(c[1])
        z=0
        for i in range(m):
            if b[i]:z=0
            else:
                z+=1
                if z==k:break
        else:
            print('NULL')
            continue
        print(r)
        d[r]=i-k+1
        s[r]=k
        for j in range(len(l)):
            if d[l[j]]>d[r]:
                l=l[:j]+[r]+l[j:]
                break
        else:
            l.append(r)
        for j in range(i-k+1,i+1):b[j]=1
        r+=1
    elif c[0]=='erase':
        k=int(c[1])
        if 0<=k<=t and d[k]+1:
            l.remove(k)
            for i in range(d[k],d[k]+s[k]):b[i]=0
            d[k]=-1
        else:
            print('ILLEGAL_ERASE_ARGUMENT')
    else:
        b=[1]*sum(b)+[0]*(m-sum(b))
        e={i:-1 for i in range(t+1)}
        n=0
        for i in l:
            e[i]=n
            n+=s[i]
        d=e
    print(c,b,d,s,sep='\n',end='\n\n')
