from sys import stdin
"""
n=int(stdin.readline().strip())
n,m=map(int,stdin.readline().strip().split())
s=list(map(int,stdin.readline().strip().split()))
"""
n,m=map(int,stdin.readline().strip().split())
s=[list(map(int,stdin.readline().strip().split())) for i in range(n)]
ans=-10**40
for j in range(m):
    mn=10**20
    for i in range(n):
        mn=min(mn,s[i][j])
    if mn>ans:
        ans=mn
print(ans)
