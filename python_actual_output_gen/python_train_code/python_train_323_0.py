while 1:
    try:
        v,d=map(int,input().split())
        f=[0]*(v+1)
        f[0],f[1]=1,2
        for i in range(2,v+1):
            f[i]=f[i-1]+f[i-2]
        f.sort()
        c=1
        for i in range(2,v+1):
            if f[i]-f[i-1]>=d: c+=1
        print(c)
    except:break