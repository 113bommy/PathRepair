from sys import stdin
n,m=map(int,stdin.readline().strip().split())
s=list(map(int,stdin.readline().strip().split()))
s1=list(map(int,stdin.readline().strip().split()))
if min(s1)<max(s):
    print(-1)
    exit(0)
s.sort()
s1.sort()

ans=0
if s1[0]!=s[-1]:
    ans+=s1[0]
    ans+=s[-2]*(m-1)
    ans+=sum(s1[1::])
    ans+=s[-1]
    for i in range(n-2):
        ans+=s[i]*m
else:
    ans+=sum(s1)
    for i in range(1,n-1):
        ans+=s[i]*m   
print(ans)
