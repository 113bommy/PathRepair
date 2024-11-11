n=int(input())
l=list(map(int,input().split()))
m=l[0]
index=1
for i in range(1,n):
    if(l[i]>m):
        index=i+1
        m=l[i]
sm=l[0]
for i in range(2,n):
    if(i!=index-1 and l[i]>sm):
        sm=l[i]
print(index,sm)
