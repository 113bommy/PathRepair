from fractions import gcd
n=int(input())
m=list(map(int,input().split()))
m.sort()
g=m[1]-m[0]
for i in range(2,n):
    g=gcd(g,m[i]-m[i-1])
ans=0
for i in range(1,n):
    ans+=(m[i]-m[i-1])//g
print(ans)