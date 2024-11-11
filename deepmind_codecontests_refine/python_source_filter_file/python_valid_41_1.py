
import sys
input=sys.stdin.readline #文字列入力はするな！！


n,m=map(int,input().split())
s=list(input())[:-1]
for i in range(n):
    s[i]=ord(s[i])-97

print(s)

x=[i%3 for i in range(n)]
y=[(i+1)%3 for i in range(n)]
z=[(i+2)%3 for i in range(n)]
a=[i%3 for i in range(n,0,-1)]
b=[(i+1)%3 for i in range(n,0,-1)]
c=[(i+2)%3 for i in range(n,0,-1)]

sx=[0]*(n+1)
sy=[0]*(n+1)
sz=[0]*(n+1)
sa=[0]*(n+1)
sb=[0]*(n+1)
sc=[0]*(n+1)
for i in range(n):

    sx[i]=sx[i-1]
    if x[i]!=s[i]:
        sx[i]+=1

    sy[i] = sy[i - 1]
    if y[i] != s[i]:
        sy[i] += 1

    sz[i] = sz[i - 1]
    if z[i] != s[i]:
        sz[i] += 1

    sa[i] = sa[i - 1]
    if a[i] != s[i]:
        sa[i] += 1

    sb[i] = sb[i - 1]
    if b[i] != s[i]:
        sb[i] += 1

    sc[i] = sc[i - 1]
    if c[i] != s[i]:
        sc[i] += 1

def get(l,r):
    res=10**18
    res=min(res,sx[r]-sx[l-1])
    res = min(res, sy[r] - sy[l - 1])
    res = min(res, sz[r] - sz[l - 1])
    res = min(res, sa[r] - sa[l - 1])
    res = min(res, sb[r] - sb[l - 1])
    res = min(res, sc[r] - sc[l - 1])
    return res






for _ in range(m):
    l,r=map(int,input().split())
    l-=1
    r-=1
    print(get(l,r))





