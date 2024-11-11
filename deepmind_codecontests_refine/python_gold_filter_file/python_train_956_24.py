n,m,jump=map(int,input().split())
a=list(map(int,input().split()))
total=0
for i in range(m):
    total+=a[i]
dist=n-total
b=dist//(m+1)
visited=[b for i in range(n)]
if(dist%(m+1)>0):
    b+=1
if(b>=jump):
    print("NO")
else:
    for i in range(dist%(m+1)):
        visited[i]+=1
    final=[0 for i in range(n)]
    i=0
    count=1
    j=0
    while(i<m):
        j+=visited[i]
        for k in range(j,j+a[i]):
            final[k]=count
        j+=a[i]
        count+=1
        i+=1
    print("YES")
    for i in range(n):
        print(final[i],end=' ')
    print()