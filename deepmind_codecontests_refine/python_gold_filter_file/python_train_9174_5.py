
n,m,k=map(int,input().split())
ar=[]
l=list(map(int,input().split()))
for i in range(n-1):
    ar.append(l[i+1]-l[i])
ar.sort()
print(sum(ar[:n-k])+k)
