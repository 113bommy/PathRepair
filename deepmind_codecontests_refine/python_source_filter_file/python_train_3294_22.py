t=int(input())

ans=[0]*300

for i in range(t):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))

    b=max(a[0],n+1-a[k-1])
    m=-1
    for j in range(k-1):
        m=max(m,a[j+1]-a[j])
    ans[i]=max((m+1)//2,b)

for i in range(t):
    print(ans[i])







