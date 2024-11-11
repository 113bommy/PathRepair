def check(n,m,star,d,f):
    ns=[i for i in range(n)]
    for i in range(d):
        for j in range(n-1):
            if f[i][j]:
                c=ns[j+1]
                ns[j+1]=ns[j]
                ns[j]=c
    return ns[star-1]==m-1



while True:
    n=int(input())
    if(n==0):break
    m=int(input())
    star=int(input())
    d=int(input())
    f=[[False for i in range(n-1)]for j in range(d)]
    for i in range(d):
        st=input()
        for j in range(n-1):
            f[i][j]=st[j]=='1'
    if check(n,m,star,d,f):
        print(1)
    else:
        ans=False
        for i in range(d):
            for j in range(n-1):
                if ans:break
                ok=not f[i][j]
                if(j>0 and f[i][j-1]) or (j<n-2 and f[i][j+1]):ok=False
                if ok:
                    f[i][j]=True
                    if check(n,m,star,d,f):
                        print(i+1,j+1)
                        ans=True
                    f[i][j]=False
        if not ans:
            print(0)