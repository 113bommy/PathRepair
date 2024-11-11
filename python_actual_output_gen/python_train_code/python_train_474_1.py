n,k=map(int,input().split())
a=list(map(int,input().split()))
m=0
if n==k:
    print(sum(a))
    quit()
b=[sum(a[:k])]
m=max(b[0]/k,m)
for i in range(n-k):
    b+=[b[i]-a[i]+a[k+i]]
    m=max(b[i+1]/k,m)
for j in range(n-k):
    b.pop(-1)
    for i in range(n-k-j):
        b[i]=b[i]+a[k+j+i]
        m=max(b[i]/(k+1+j),m)
print(m)
