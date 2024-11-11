n,k=map(int,input().split())
a=list(map(int,input().split()))
r=[]
p=sum(a[:k])
s=p
m=0
for i in range(1,n-k+1):
    s=s-a[i-1]+a[i+k-1]
    if s<p:
        p=s
        m=i
print(m+1)
