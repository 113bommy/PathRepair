c=[0 for i in range(1000)]
n=int(input())
cc=[]
for i in range(n):
    a=list(map(int,input().strip().split(' ')))
    for j in a:
        c[j]=1
    cc.append(a)
if(n==1):
    for i in range(1,1000):
        if(c[i]==0):
            break
    print(i-1)
if(n==2):
    a=cc[0]
    b=cc[1]
    for i in a:
        for j in b:
            c[i*10+j]=1
            c[j*10+i]=1
    for i in range(1,1000):
        if(c[i]==0):
            break
    print(i-1)
if(n==3):
    a=cc[0]
    b=cc[1]
    d=cc[2]
    
    for i in a:
        for j in b:
            c[i*10+j]=1
            c[j*10+i]=1
    for i in a:
        for j in d:
            c[i*10+j]=1
            c[j*10+i]=1
    for i in d:
        for j in b:
            c[i*10+j]=1
            c[j*10+i]=1
    for i in a:
        for j in b:
            for k in d:
                c[i*100+j*10+k]=1
                c[i*100+k*10+j]=1
                c[j*100+i*10+k]=1
                c[j*100+i+k*10]=1
                c[k*100+i*10+j]=1
                c[k*100+j*10+i]=1
    
    for i in range(1,1000):
        if(c[i]==0):
            break
    print(i-1)

