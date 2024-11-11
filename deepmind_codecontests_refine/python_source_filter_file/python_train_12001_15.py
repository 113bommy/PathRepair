t=int(input())
for _ in range(t):
    n,k=list(map(int,input().split()))
    a=list(map(int,input().split()))
    m=min(a)
    c=0
    ans=0
    for i in range(n):
        if a[i]==m and c==0:
            c=c+1
        else:
            ans=ans+min(k-a[i],0)//m
    print(ans)