n,k=map(int,input().split())
V=list(map(int,input().split()))
L=[]
ans=0
for i in range(n):
    for j in range(n-i):
        if i+j>k:
            continue
        tmp=V[:i]+V[n-j:]
        tmp.sort(reverse=True)
        for l in range(k-i-j):
            if tmp and tmp[-1]<0:
                tmp.pop()
            else:
                break
        ans=max(ans,sum(tmp))
print(ans)