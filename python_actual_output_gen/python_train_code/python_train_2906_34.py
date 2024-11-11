t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    ans=[]
    val=[]
    for j in range(n):
        if a[j] in val:
            ans.append(a[j])
        else:
            val.append(a[j])
    print(*ans,sep=" ")