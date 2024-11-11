l=[]
for _ in range(int(input())):
    N=int(input())
    a=list(map(int,input().split()))
    a.sort()
    n=0
    p=0
    z=0
    for i in range(N):
        if a[i]<0:
            n=n+1
        elif a[i]==0:
            z=z+1
        else:
            p=p+1
    if N-z<5 and z!=0:
        l.append(0)
    elif p==0 and z!=0:
        l.append(0)
    elif p==0:
        l.append(a[-1]*a[-5]*a[-2]*a[-3]*a[-4])
    else:
        if p==1:
            l.append(a[-1]*a[0]*a[1]*a[2]*a[3])
        elif p==2:
            l.append(a[-1] * a[0] * a[1] * a[2] * a[3])
        elif p==3:
            l.append(max(a[-1] * a[0] * a[1] * a[2] * a[3],a[-1] * a[0] * a[1] * a[-3] * a[-2]))
        elif p==4:
            l.append(max(a[-1] * a[0] * a[1] * a[2] * a[3],a[-1] * a[0] * a[1] * a[-3] * a[-2]))
        elif p>=5:
            l.append(max(a[-1] * a[0] * a[1] * a[2] * a[3],a[-1] * a[0] * a[1] * a[-3] * a[-2],a[-1]*a[-2]*a[-3]*a[-4]*a[-5]))
for i in l:
    print(i)