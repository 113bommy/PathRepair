import math
n,k=map(int,input().split())
l=list(map(int,input().split()))
i=sum(l)
q=0
for b in range(n-k):
    l1=l[b:n:k]
    s=sum(l1)
    q=max(abs(i-s),q)
print (q)
