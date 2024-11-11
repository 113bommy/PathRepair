n=int(input())
l=0
c=0
for i in range (n):
    k=list(map(int,input().split()))
    if(c+k[1]-k[0]>l):
        l=c-k[0]+k[1]
    c=c+k[1]-k[0]
print(l)
