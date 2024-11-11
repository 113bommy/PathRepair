t=int(input())
for _ in range(t):
    n,x=map(int,input().split())
    a=list(map(int,input().split()))
    l=-1
    sum=0
    c=0
    for i in range(n):
        if a[i]%x==0:
            if l==-1:
                l=i 
            k=i 
            c+=1
        sum+=a[i]
    if sum%x!=0:
        print(n)
    elif(l==-1):
        print(-1)
    else:
        print(n-min(l+1,n-k))
        