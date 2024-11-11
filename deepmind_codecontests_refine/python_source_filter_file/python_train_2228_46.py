n,k=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
m=l[n-1]-l[0]
for i in range(n-k+1):
    m=min(m,l[i+n-1]-l[i])
print(m)