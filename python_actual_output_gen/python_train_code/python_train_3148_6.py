n,m,k=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
d=[]
for i in range(1,n):
    d.append(l[i]-l[i-1])
print(sum(d[:n-k])+k)
