n,a=map(int,input().split())
t=list(map(int,input().split()))
s=0
i=a-2
j=a
while i>=0 and j<n:
    if t[i]==1 and t[j]==1:
        s=s+2
    i=i-1
    j=j+1
if i==-1:
    for z in range(j,n):
        if t[z]==1:
            s=s+1
if j==n:
    for z in range(i,-1):
        if t[z]==1:
            s=s+1
s=s+t[a-1]
print(s)