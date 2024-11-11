n=int(input())
l=list(map(int,input().split()))
x=[0]*(n+1)
d=dict()
for i in range(n):
    x[i+1]=x[i+1]+x[i]+l[i]
s=0
c=0
for i in range(n):
    if(x[i] in d):
        d[x[i]]+=1
    else:
        d[x[i]]=1
    while(d[x[i]]>1):
        d[x[c]]-=1
        c=c+1
    s=s+(i-c+1)
print(s-n-1)
