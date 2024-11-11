import sys
input=sys.stdin.readline
def f(t):
    ok=t%n
    p=pref[-1]
    lol=t//n
    z1=x1+(lol)*p[0]
    z2=y1+(lol)*p[1]
    #print(z1,z2)
    #print(pref)
    if(ok>=1):
        z1+=pref[ok-1][0]
        z2+=pref[ok-1][1]
    #print(z1,z2)
    y=abs(z1-x2)+abs(z2-y2)
    if(y<=t):
        return 1
    return 0
def bsearch(l,r):
    while(l<r):
        m=(l+r)//2
        if(f(m)):
            r=m
        else:
            l=m+1
    return l
l=input().split()
x1=int(l[0])
y1=int(l[1])
l=input().split()
x2=int(l[0])
y2=int(l[1])
n=int(input())
s=input()
pref=[[0,0] for i in range(n)]
#right,up
if(s[0]=='R'):
    pref[0]=[1,0]
if(s[0]=='U'):
    pref[0]=[0,1]
if(s[0]=='L'):
    pref[0]=[-1,0]
if(s[0]=='D'):
    pref[0]=[0,-1]
for i in range(1,n):
    pref[i]=list(pref[i-1])
    if(s[i]=='R'):
        pref[i][0]+=1
    if(s[i]=='L'):
        pref[i][0]-=1
    if(s[i]=='U'):
        pref[i][1]+=1
    if(s[i]=='D'):
        pref[i][1]-=1
ok=bsearch(0,4*(10**14))
#print(f(4))
if(f(ok)):
    print(ok)
else:
    print(-1)