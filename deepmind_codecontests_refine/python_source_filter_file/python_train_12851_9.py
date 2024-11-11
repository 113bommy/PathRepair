n,m=map(int,input().split())
l=list(map(int,input().split()))
c=[-1]*(101)
for i in range(0,n):
    if l[i]<m:
        c[0]=i
    else:
        if l[i]%m == 0:
            a=l[i]//m
            c[a]=i
        else:
            a=l[i]//m + 1
            c[a]=i
ind=0            
for i in range(0,101):
    if c[i]!=-1:
        ind=c[i]
print(ind+1)        