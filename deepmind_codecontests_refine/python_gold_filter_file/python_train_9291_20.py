for _ in range(int(input())):
    n,k=map(int,input().split())
    l=[[0 for j in range(n)]for i in range(n)]
    j=0
    if k==0:
        print(0)
        for i in range(0,n):
            for j in range(0,n):print(0,end="")
            print()
        continue   
    count=[0]*n
    if k%n==0:
        b,j=(k//n),n-1
        for i in range(0,n):
            a=(j-b+1)
            if a<0:
                a=a%n
                for m in range(a,n):
                    l[i][m]=1
                    count[m]+=1
                for m in range(0,j+1):
                    l[i][m]=1
                    count[m]+=1
            else:
                for m in range(a,j+1):
                    l[i][m]=1
                    count[m]+=1
            j-=1    
    else:
        b,ct,fg,j=(k//n + 1),k%n,0,n-1
        for i in range(0,n):
            if i>=ct and fg==0:
                b-=1;fg=1
            a=(j-b+1)    
            if a<0:
                a=a%n
                for m in range(a,n):
                    l[i][m]=1
                    count[m]+=1
                for m in range(0,j+1):
                    l[i][m]=1
                    count[m]+=1
            else:
                for m in range(a,j+1):
                    l[i][m]=1
                    count[m]+=1
            j-=1   
    mxr,mxc,mir,mic=-1,-1,1000,1000   
    for i in range(0,n):
        a=l[i].count(1)
        mir=min(mir,a)
        mxr=max(mxr,a)
    mic=min(count)
    mxc=max(count)
    f=(mxr-mir)**2+(mxc-mic)**2
    print(f)
    for i in range(0,n):
        for j in range(0,n):
            print(l[i][j],end="")
        print()    
        