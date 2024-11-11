n,m,d=map(int,input().split())
a=list(map(int,input().split()))
s=sum(a)
if n>s+(m+1)*(d-1):
    print("NO")
else:
    print("YES")
    e=n-s
    if d==1:
        l=[]
        i=1
        for j in a:
            l+=[i]*j
            i+=1
        print(*l)
    else:
        q=e//(d-1)
        r=e%(d-1)
        l=[]
        i=1
        if r==0 and q!=0:
            q-=1
            r=d-1
        for j in range(q):
            l+=[0]*(d-1)
            l+=[i]*a[j]
            i+=1
        l+=[0]*r
        for j in range(q,m):
            l+=[i]*a[j]
            i+=1
        print(*l)