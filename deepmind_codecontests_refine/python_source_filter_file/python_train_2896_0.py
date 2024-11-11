n,kk=map(int,input().split())
ss=input().split()
a=[int(ss[i]) for i in range(n)]
s=[0]*(n+1)
for i in range(n):
    s[i+1]=s[i]+a[i]
b=[None for i in range(n*(n+1)//2)]
k=0
for i in range(n):
    for j in range(i+1,n+1):
        b[k]=s[j]-s[i]
        k+=1
res=0
for i in range(30,-1,-1):
    m=2**i
    cnt=0
    for j in b:
        if j&m>0:
            cnt+=1
    if cnt>=kk:
        bb=[0 for j in range(cnt)]
        k=0
        for j in b:
            if j&m>0:
                bb[k]=j
                k+=1
        b=list(bb)
        res+=m
print(res)