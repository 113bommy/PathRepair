n,q=map(int,input().split())
a=[]
for i in range(q):
    x,y=map(int,input().split())
    t=(x-1)*n+y
    ans=(t+1)//2
    if ((x+y)%2==1):
        ans=ans+((n*n+1)//2)
    a.append(ans)
for i in range(q):
    print(a[i])
