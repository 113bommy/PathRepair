from sys import stdin
n,m=map(int,stdin.readline().strip().split())
s=list(map(int,stdin.readline().strip().split()))
s1=list(map(int,stdin.readline().strip().split()))
ans=10**20
for i in range(n):
    ans1=0
    for j in range(m):
        
        for k in range(n):
            if k==i:
                continue
            ans1=max(ans1,s[k]*s1[j])
    ans=min(ans1,ans)
print(ans)
