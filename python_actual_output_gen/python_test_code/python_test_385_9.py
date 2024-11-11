n=int(input())
a=[]
p=[]
for i in range(n):
    ai,pi=map(int,input().split())
    a.append(ai)
    p.append(pi)
cost=0
k=0
while(k<n-1):
    for j in range(k,n):
        if(p[j]<p[k]):
            j-=1
            break
    cost+=(sum(a[k:j+1]))*p[k]
    k=j+1
    if(k==n-1):
        cost+=a[k]*p[k]
print(cost)