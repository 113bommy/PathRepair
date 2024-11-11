def summ(q):
    return int((q+1)*q/2)
t=int(input())
for i in range(t):
    n=int(input())
    b=[0]*n
    a=list(map(int,input().split()))
    s=sum(a)
    l=summ(n)
    e=0
    m=0
    if s%l==0:
        m=s//l
    else:
        e=-1
    b[0]=a[0]-a[-1]-m
    ss=-1
    if b[0]>0:
        e=-1
    else:
        b[0]=abs(b[0])
    if s<n:
        e=-1
    if b[0]<0:
        e-=1
    else:
        if b[0]%n!=0:
            e-=1
        else:
            b[0]=b[0]//n
            ss=b[0]
    if e==0:
        for j in range(n-1):
            b[j+1]=a[j+1]-a[j]-m
            if b[j+1]>=0:
                e=-1
                break
            else:
                b[j+1]=abs(b[j+1])
            if b[j+1]<=0:
                e=-1
                break
            else:
                if b[j+1]%n!=0:
                    e=-1
                    break
                else:
                    b[j+1]=b[j+1]//n
                    if b[j+1]==0:
                        e=-1
                        break
                    else:
                        ss+=b[j+1]
    if (e==-1)or(ss!=m):
        print('NO')
    else:
        print('YES')
        for j in b:
            print(j,end=' ')
        print()