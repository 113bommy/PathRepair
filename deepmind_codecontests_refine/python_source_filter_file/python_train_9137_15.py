n,p=map(int,input().split())
s=input()
if p==2 or p==5:
    a=0
    for i in range(n):
        if int(s[i])%p==0:
            ans+=n
    print(a)
else:
    a=0
    g=[0]*(n+1)
    t=[0]*p
    t[0]=1
    d=1
    for i in range(n-1,-1,-1):
        g[i]=(g[i+1]+int(s[i])*d)%p
        a+=t[g[i]]
        t[g[i]]+=1
        d*=10
        d%=p
    print(a)
