def kandane(z):
    
    cur=z[0]
    maxa=z[0]
    start=1
    end=1
    for i in range(1,len(z)):
       
        cur=max(cur+z[i],z[i])
        maxa=max(maxa,cur)
        return maxa;
a=int(input())
for i in range(a):
    x=input()
    z=list(map(int,input().split()))
    t=z.copy()
    r=z.copy()
    w=z.copy()
    t[0]=0
    r[-1]=0
    w[0]=0
    w[-1]=0
    
    m2=kandane(t)
    m3=kandane(r)
    m4=kandane(w)
    
    if(len(z)==2):
        if(max(m2,m3)>=sum(z)):
            print('NO')
        else:
            print('YES')
    else:
        
        if(max(m2,m3,m4)>=sum(z)):
            print('NO')
        else:
            print('YES')
        
