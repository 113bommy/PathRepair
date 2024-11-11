t=int(input())
for j in range(t):
    n=int(input())
    arr=list(map(int,input().strip().split()))
    d=dict()
    for i in range(n+1):
        d[i]=0
    for j in arr:
        d[j]=d[j]+1
    mex=0
    for i in range(n+1):
        if(d[i]==0):
            mex=i
            break
    k=0
    crr=[]
    while(k<(2*n)):
        if(mex==n):
            flag=0
            for i in range(n):
                if(arr[i]!=i):
                    flag=1
                    break
            if(flag==1):
                t=arr[i]
                crr.append(i)
                arr[i]=mex
                d[t]=d[t]-1
                d[mex]=d[mex]+1
            elif(flag==0):
                break
        if(mex<n):
            t=arr[mex]
            arr[mex]=mex
            d[t]=d[t]-1
            d[mex]=d[mex]+1
            crr.append(mex)
        k=k+1
        for i in range(n+1):
            if(d[i]==0):
                mex=i
                break
    print(k)
    for i in crr:
        print(i,end=" ")
    print(" ")        
            
        