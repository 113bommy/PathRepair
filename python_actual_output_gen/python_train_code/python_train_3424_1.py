n,k=map(int,input().split())
l=list(map(int,input().split()))
s=[11**11,sum(l[0:k])]
for i in range(1,n-k):
    s+=[s[-1]-l[i-1]+l[i+k-1]]
print(s.index(min(s)))