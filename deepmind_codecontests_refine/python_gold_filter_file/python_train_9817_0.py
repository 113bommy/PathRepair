def sort(c,a):
    for i in range(0,3):
        c[i]-=a[i]
        if(c[i]<0):
            return False
    if(a[3]>0):
        if(c[0]>0):
            if(c[0]>=a[3]):
                c[0]-=a[3]
                a[3]=0
            else:
                a[3]-=c[0]
                c[0]=0
                c[2]-=a[3]
                if(c[2]<0):
                    return False
        else:
            c[2]-=a[3]
            a[3]=0
            if c[2]<0:
                return False
    if(a[4]>0):
        if(c[1]>0):
            if(c[1]>=a[4]):
                c[1]-=a[4]
                a[4]=0
            else:
                a[4]-=c[1]
                c[1]=0
                c[2]-=a[4]
                if(c[2]<0):
                    return False
        else:
            c[2]-=a[4]
            a[4]=0
            if c[2]<0:
                return False
    return True
        
t=int(input())
for _ in range(t):
    c=list(map(int,input().split()))
    a=list(map(int,input().split()))
    if(sort(c,a)==True):
        print("YES")
    else:
        print("NO")
        