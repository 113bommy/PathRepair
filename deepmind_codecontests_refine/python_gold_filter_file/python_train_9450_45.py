n,k=map(int,input().split())
a=list(map(int,input().split()))

s=[]
d=[-1]*(n+1)

v=1
while(d[v]==-1):
    d[v]=len(s)
    s.append(v)
    v=a[v-1]
c=len(s)-d[v]
l=d[v]

if(k<l):print(s[k])
else:
    k-=l
    k%=c
    print(s[k+l])