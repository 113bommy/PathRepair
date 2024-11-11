n,k=map(int,input().split())
a= list(map(int,input().split()))
b= list(map(int,input().split()))
su=0
for i in range(n):
    if b[i]:
        su+=a[i]
        a[i]=0
ma=sum(a[:k]) 
for j in range(0,n-k):
    s=(ma+a[j+k])-a[j]
    ma=max(ma,s)
print(su+ma)