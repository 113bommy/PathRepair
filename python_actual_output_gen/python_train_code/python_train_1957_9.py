n=int(input())
l=0
c=0
for i in range (n):
    k=list(map(int,input().split()))
    if(k[1]-k[0]>0):
        l=c+k[1]-k[0]
    c=c+k[1]-k[0]
print(l)
