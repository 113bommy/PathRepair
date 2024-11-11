n,m=map(int,input().split())
a=list(map(int,input().split()))
s=0
for i in range(len(a)-1):
    if a[i+1]-a[i]<=m:s=s+1
    else:s=1
print(s)