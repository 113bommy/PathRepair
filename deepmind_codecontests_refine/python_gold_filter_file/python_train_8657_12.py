def fu(a,b):
    e=0
    for i in range(1,len(a)):
        if a[i]!=a[0]+i*b:
            e+=1
            if e==1:
                f=i
            if e>1:
                e=-1
            break
    if e==-1:
        return -1
    else:
        return f
    
n=int(input())
a=list(map(int,input().split()))
a=[[a[i],i] for i in range(n)]
a.sort()

if n<4:
    print(a[0][1]+1)
else:
    b=[]
    for i in range(n):
        b.append(a[i][0])
    e=0
    for i in range(1,n):
        if b[i]!=b[1]+(i-1)*(b[2]-b[1]):
            e=-1
            break
    if e==-1:
        d=[b[0]]+b[2:]
        e=0
        for i in range(len(d)):
            if d[i]!=d[0]+i*(d[1]-d[0]):
                e=-1
                break
        if e==-1:
            e=0
            i=0
            while i<n:
                if b[i]!=b[0]+(i-e)*(b[1]-b[0]):
                    e+=1
                    if e==1:
                        f=a[i][1]+1
                    if e>1:
                        e=-1
                        break
                i+=1
            if e==-1:
                print(e)
            else:
                print(f)
                    
        else:
            print(a[1][1]+1)
    else:
        print(a[0][1]+1)
    