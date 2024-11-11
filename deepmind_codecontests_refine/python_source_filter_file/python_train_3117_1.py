while 1:
    m,nn,nx= map(int,input().split())
    if m==0: break
    s=[int(input()) for _ in range(m)]
    v=k=0
    for i in range(nn-1,nx):
        t=s[i]-s[i+1]
        if v<t:
            k,v=i+1,t
    print(k)