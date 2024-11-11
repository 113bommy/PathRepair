n,k=map(int,input().split())
l=list(map(int,input().split()))
d=[0]*n
d[0]=0
for i in range(1,n):
    x=l[i]
    d[i]=min([d[j]+abs(l[j]-x) for j in range(max(0,i-k),i)])
print(d[n-1])