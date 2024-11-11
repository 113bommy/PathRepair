n,k=map(int,input().split())
l=list(map(int,input().split()))
s=0
j=0
for i in range(k):
    s=s+l[i]
m=s
for i in range(k,n):
    s=s+l[i]-l[i-k]
    if s<m:
        m=s
        j=i-k+1
print(j)