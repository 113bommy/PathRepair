n= int(input())
rank=0

m=list(map(int,input().split()))
k=list(map(int,input().split()))

dif = k[1]-k[0]

for z in range(k[0]-1,len(k)):
    if dif==0:
        break
    dif-=1
    rank = rank + m[z]
print(rank)