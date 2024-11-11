n=int(input())
w=list(map(int,input().split()))
ans=[]
w.sort()
ans=float('inf')
n*=2
for i in range(n-1):
    for j in range(i+1,n):
        cur=0
        a=list(w[:i]+w[i+1:j]+w[j+1:])
        for k in range(len(a)-1):
            cur+=a[k+1]-a[k]
        ans=min(ans,cur)
print(ans)