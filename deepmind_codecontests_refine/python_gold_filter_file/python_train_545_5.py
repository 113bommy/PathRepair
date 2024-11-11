from sys import stdin
"""
n=int(stdin.readline().strip())
n,m=map(int,stdin.readline().strip().split())
s=list(map(int,stdin.readline().strip().split()))
s=stdin.readline().strip()
"""
n=int(stdin.readline().strip())
s=list(map(int,stdin.readline().strip().split()))
if n==1:
    print(1,1)
    print(0)
    print(1,1)
    print(0)
    print(1,1)
    print(-s[0])

    exit(0)
d=[-1 for i in range(n)]
for i in range(2*n):
    x=(i*(n-1))%n
    if d[x]==-1:
        d[x]=i
print(1,n-1)
ans=[]
for i in range(n-1):
    y=(n-s[i])%n
    s[i]+=d[y]*(n-1)
    ans.append(d[y]*(n-1))
print(*ans)
print(2,n)
ans=[]
for i in range(1,n):
    y=(n-s[i])%n
    s[i]+=d[y]*(n-1)
    ans.append(d[y]*(n-1))
print(*ans)
print(1,n)
ans=[]
for i in range(n):
    ans.append(-s[i])

print(*ans)
        
    
    
    
