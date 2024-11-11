t=int(input())
s=[]
for knvjf in range(0,t):
    n=int(input())
    x=input()
    p=x.split( )
    m=int(input())
    x=input()
    q=x.split( )
    p0=0
    q0=0
    fp=0
    fq=0
    zp=0
    zq=0
    for i in p:
        if int(i)%2==1:
            fp+=1
        else:
            if i=='0':
                p0+=1
            else:
                zp+=1
    for i in q:
        if int(i)%2==1:
            fq+=1
        else:
            if i=='0':
                q0+=1
            else:
                zq+=1
    g=zp*zq+fp*fq+p0*zq+q0*zp
    s.append(g)
for i in s:
    print(i)
                
